# print_hpp

print everything!

`print_hpp` is a header only library for modern cpp.

## Usage

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
    print(Person{.name = "zhangsan", .age = 18});

    // you should define print_custom::printer<T>
    LOG_INFO("print_custom::printer<T>: {}",
             pretty(std::vector{"R", "G", "B", "Y"}));
    LOG_INFO("print_custom::printer<T>: {}",
             pretty(Person{.name = "wangmazi", .age = 36}));
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
2024-05-26 13:00:00.000 |INFO | ../tests/test_print.cpp:79 print_custom::printer<T>: ["R", "G", "B", "Y"]
2024-05-26 13:00:00.000 |INFO | ../tests/test_print.cpp:80 print_custom::printer<T>: {"wangmazi", 36}
```
