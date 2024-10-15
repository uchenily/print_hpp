#include "aggregate_arity.hpp"
#include <cassert>
#include <string>

struct Person {
    std::string name;
    int         age;
};

auto main() -> int {
    auto zhangsan = Person{"zhangsan", 18};

    static_assert(reflect::num_fields<Person>() == 2);

    assert(reflect::get<0>(zhangsan) == "zhangsan");
    assert(reflect::get<1>(zhangsan) == 18);
}
