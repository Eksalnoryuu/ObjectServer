load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

_ALL_CONTENT = """\
filegroup(
    name = "all_srcs",
    srcs = glob(["**/**/**"]),
    visibility = ["//visibility:public"],
)
"""

def download_zeromq():
    http_archive(
        name = "zeromqcpp",
        build_file_content = _ALL_CONTENT,
        strip_prefix = "cppzmq-4.10.0",
        sha256 = "54d5d8315fd6116124ac7eec411610ae21652dca70c0bc936db5f2cccf4ad60b",
        url = "https://github.com/zeromq/cppzmq/archive/refs/tags/v4.10.0.zip",
    )
