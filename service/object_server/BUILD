load("@rules_cc//cc:defs.bzl", "cc_binary")
load("@io_bazel_rules_docker//container:container.bzl", "container_push")
load("@io_bazel_rules_docker//cc:image.bzl", "cc_image")

cc_binary(
    name = "object_server",
    srcs = ["main.cpp"],
    deps = [
        "//libs/object_server",
    ],
)

cc_image(
    name = "image",
    base = "//images:cpp_base_v2",
    binary = ":object_server",
    visibility = ["//visibility:public"],
)

