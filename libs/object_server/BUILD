load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "object_server",
    srcs = glob(["src/**/*.cpp"]),
    hdrs = glob([
        "src/**/*.h",
        "*.h",
        "src/**/*.inl",
        "*.inl",
    ]),
    visibility = ["//visibility:public"],
    deps = [
        "//third_party/spdlog",
        "//third_party/sqlite",
        "//third_party/json",
        "//third_party/boost:system",
        "//libs/utils",
        "//third_party/zeromqcpp",
    ],
)