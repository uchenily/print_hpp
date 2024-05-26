#include "print.hpp"

#include <list>
#include <map>
#include <optional>
#include <string_view>
#include <tuple>
#include <variant>
#include <vector>

struct Person {
    std::string name;
    int         age;
};

namespace print_custom {
template <>
class printer<Person> {
public:
    auto print(const Person &person, std::ostream &out) {
        out << '{';
        print_to(out, person.name);
        out << ", ";
        print_to(out, person.age);
        out << '}';
    }
};
} // namespace print_custom

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
    print(std::optional<int>{3});
    print(std::optional<int>{std::nullopt});
    print(std::nullopt);
    print(std::tuple{"red", false, 3.14});
    print(Person{.name = "zhangsan", .age = 18});
}
