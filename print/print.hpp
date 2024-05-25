#pragma once

#include <array>
#include <iostream>
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

template <typename T>
auto print(T t) {
    if constexpr (std::is_convertible_v<T, std::string_view>) {
        std::cout << t << '\n';
    } else {
        std::cout << "unprintable type " << print_detail::name_of<T>() << '\n';
    }
}
