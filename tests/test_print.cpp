#include "print.hpp"

#include <list>
#include <map>
#include <string_view>
#include <variant>
#include <vector>

auto main() -> int {
    print("hello");
    print(std::string{"hello"});
    print(std::string_view{"hello"});
    print(true);
    print(3);
    print(3.14);
    print(std::vector{1, 2, 3});
    print(std::list{1.0, 2.0, 3.0});
    print(std::map<std::string, std::variant<std::string, int>>{
        {"hello", "world"},
        { "work",     996},
    });
}
