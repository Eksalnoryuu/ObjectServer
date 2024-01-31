load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")

cmake(
    name = "zeromqcpp",
    lib_source = "@zeromqcpp//:all_srcs",
    out_headers_only = True,
    visibility = ["//visibility:public"],
    deps = ["@system//:libzmq"],
)
