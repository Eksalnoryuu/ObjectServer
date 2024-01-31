load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")

cmake(
    name = "sqlite",
    lib_source = "@sqlitecpp_src//:all_srcs",
    out_static_libs = ["libSQLiteCpp.a"],
    visibility = ["//visibility:public"],
    deps = ["@system//:sqlie3"],
)
