load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

_ALL_CONTENT = """\
filegroup(
    name = "all_srcs",
    srcs = glob(["**/**/**"]),
    visibility = ["//visibility:public"],
)
"""

def download_json():
    http_archive(
        name = "json_src",
        build_file_content = _ALL_CONTENT,
        strip_prefix = "json-3.11.3",
        sha256 = "04022b05d806eb5ff73023c280b68697d12b93e1b7267a0b22a1a39ec7578069",
        url = "https://github.com/nlohmann/json/archive/refs/tags/v3.11.3.zip",
    )
