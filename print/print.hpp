#pragma once

#include <iostream>
#include <type_traits>

template <typename T>
auto print(T t) {
    if constexpr (std::is_convertible_v<T, std::string_view>) {
        std::cout << t << '\n';
    } else {
        std::cout << "unprintable type\n";
    }
}
