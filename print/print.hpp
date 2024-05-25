#pragma once

#include <iostream>
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

} // namespace print_detail

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
auto print(T t) {
    if constexpr (std::is_convertible_v<T, std::string_view>
                  || (std::is_integral_v<T> && !std::is_same_v<T, bool>)
                  || std::is_floating_point_v<T>) {
        std::cout << t << '\n';
    } else if constexpr (std::is_same_v<T, bool>) {
        std::cout << (t ? "true\n" : "false\n");
    } else if constexpr (is_mappable_v<T>) {
        std::cout << '{';
        auto first = true;
        for (const auto &elem : t) {
            if (!first) {
                std::cout << ", ";
            }
            first = false;
            std::cout << elem.first << ": " << elem.second;
        }
        std::cout << "}\n";
    } else if constexpr (is_iterable_v<T>) {
        std::cout << '{';
        auto first = true;
        for (const auto &elem : t) {
            if (!first) {
                std::cout << ", ";
            }
            first = false;
            std::cout << elem;
        }
        std::cout << "}\n";
    } else {
        std::cout << "unprintable type " << print_detail::name_of<T>() << '\n';
    }
}
