load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")

cmake(
    name = "json",
    lib_source = "@json_src//:all_srcs",
    out_headers_only = True,
    visibility = ["//visibility:public"],
)
