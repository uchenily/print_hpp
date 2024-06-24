#include "debug.hpp"

auto main() -> int {
    PRINT("{:=^60}", "hello world");
    SET_LOG_LEVEL(print_hpp::log::LogLevel::TRACE);
    LOG_TRACE("hello world");
    LOG_DEBUG("hello world");
    LOG_INFO("hello world");
    LOG_WARN("hello world");
    LOG_ERROR("hello world");
    LOG_FATAL("hello world");
    LOG(INFO)("hello world");
    LOG_IF(INFO, 1 > 0)("1 > 0");

    SET_LOG_STYLE(print_hpp::log::LogStyle::BG);
    LOG_TRACE("hello world");
    LOG_DEBUG("hello world");
    LOG_INFO("hello world");
    LOG_WARN("hello world");
    LOG_ERROR("hello world");
    LOG_FATAL("hello world");
    LOG(INFO)("hello world");
    LOG_IF(INFO, 1 > 0)("1 > 0");

    ASSERT(1 == 1);
    ASSERT_MSG(1 == 1, "1 equals 1");
}
