package(default_visibility = ["//visibility:public"])

licenses(["notice"])

cc_library(
    name = "strings",
    srcs = ["strings.cpp"],
    hdrs = ["strings.hpp"],
    includes = ["."],
)

cc_test(
    name = "strings_test",
    srcs = ["strings_test.cpp"],
    deps = [
        ":strings",
        "//third_party/gtest:gtest_main"
    ]
)