# load("@rules_cc//cc:defs.bzl", "cc_test")
# filegroup(
#     name = "config",
#     srcs = ["config/test.yml"],
#     visibility = ["//visibility:public"],
# )
# filegroup(
#     name = "test_rabbit",
#     srcs = ["config/rabbit.yml"],
#     visibility = ["//visibility:public"],
# )
# cc_test(
#     name = "unit",
#     srcs = glob([
#         "unit/**/*.cpp",
#         "unit/**/*.h",
#     ]),
#     copts = ["-Ilibs/utils/src"],
#     tags = ["unit"],
#     deps = [
#         "//libs/utils",
#         "@com_google_googletest//:gtest_main",
#     ],
# )

# cc_test(
#     name = "functional",
#     srcs = glob([
#         "functional/**/*.cpp",
#         "functional/**/*.h",
#     ]),
#     copts = ["-Ilibs/utils/src"],
#     tags = ["functional"],
#     deps = [
#         "//libs/utils",
#         "@com_google_googletest//:gtest_main",
#     ],
# )
# cc_test(
#     name = "integration",
#     srcs = glob([
#         "integration/**/*.cpp",
#         "integration/**/*.h",
#         "fixtures/**/*.h",
#     ]),
#     copts = ["-Ilibs/utils/src"],
#     tags = ["integration"],
#     data = [
#         ":config",
#         ":test_rabbit",
#     ],
#     deps = [
#         "//libs/devices",
#         "//libs/utils",
#         "@com_google_googletest//:gtest_main",
#         "//libs/io",
#     ],
# )
