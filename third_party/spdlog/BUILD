load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")

cmake(
    name = "spdlog",
    lib_source = "@spdlog_src//:all_srcs",
    out_static_libs = ["libspdlog.a"],
    visibility = ["//visibility:public"],
)
