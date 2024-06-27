# print_hpp

print everything!

`print_hpp` is a header only library for modern cpp.

## Basic Usage

```cpp
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

    LOG_INFO("{}", P(std::vector{"R", "G", "B", "Y"}));
    LOG_INFO("{}", P(Person{.name = "wangmazi", .age = 36}));
```

The output will look like this:

```python
"hello"
"hello"
"hello"
true
3
3.14
[1, 2, 3]
[1, 2, 3]
{"hello": "world", "work": 996}
3
nullopt
nullopt
("red", false, 3.14)
{"zhangsan", 18}
2024-05-26 13:00:00.000 |INFO | ../tests/test_print.cpp:79 ["R", "G", "B", "Y"]
2024-05-26 13:00:00.000 |INFO | ../tests/test_print.cpp:80 {"wangmazi", 36}
```

## Print Struct

```cpp
    struct Person {
        std::string name;
        int         age;
    };

    print(Person{.name = "zhangsan", .age = 18});
```

```
{"zhangsan", 18}
```
