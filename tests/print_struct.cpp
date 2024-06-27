#include "print.hpp"

using namespace print_hpp;

struct Person {
    std::string name;
    int         age;
};

auto main() -> int {
    auto zhangsan = Person{"zhangsan", 18};
    print(zhangsan);
}
