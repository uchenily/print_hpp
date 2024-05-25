#pragma once

#include <iostream>
#include <ostream>
#include <ranges>
#include <type_traits>

namespace print_detail {

template <typename T>
constexpr auto name_of() -> std::string_view {
    std::string_view sv;
#if __clang__
    sv = __PRETTY_FUNCTION__;
    sv = sv.substr(sv.find_last_of('=') + 2);
    sv = sv.substr(0, sv.size() - 1);
#elif __GNUC__
    sv = __PRETTY_FUNCTION__;
    sv = sv.substr(sv.find_first_of('=') + 2);
    sv = sv.substr(0, sv.find_first_of(';'));
#else
    #error "name_of not implemented on this platform"
#endif
    return sv;
}

template <typename Container>
concept is_iterable_v = requires(Container &c) {
    std::ranges::begin(c);
    std::ranges::end(c);
};

template <typename Container>
concept is_mappable_v = requires(Container &c) {
    typename Container::key_type;
    typename Container::mapped_type;
    {
        c[std::declval<const typename Container::key_type &>()]
    } -> std::same_as<typename Container::mapped_type &>;
};

template <typename T>
auto print_to(std::ostream &out, T t) {
    if constexpr (std::is_convertible_v<T, std::string_view>) {
        out << '"' << t << '"';
    } else if constexpr ((std::is_integral_v<T> && !std::is_same_v<T, bool>)
                         || std::is_floating_point_v<T>) {
        out << t;
    } else if constexpr (std::is_same_v<T, bool>) {
        out << (t ? "true" : "false");
    } else if constexpr (is_mappable_v<T>) {
        out << '{';
        auto first = true;
        for (const auto &elem : t) {
            if (!first) {
                out << ", ";
            }
            first = false;
            print_to(out, elem.first);
            out << ": ";
            print_to(out, elem.second);
        }
        out << "}";
    } else if constexpr (is_iterable_v<T>) {
        out << '{';
        auto first = true;
        for (const auto &elem : t) {
            if (!first) {
                out << ", ";
            }
            first = false;
            print_to(out, elem);
        }
        out << "}";
    } else {
        out << "unprintable type " << name_of<T>();
    }
}

} // namespace print_detail

template <typename T>
auto print(T t) {
    print_detail::print_to(std::cout, t);
    std::cout << '\n';
}
