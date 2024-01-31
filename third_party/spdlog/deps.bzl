load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

_ALL_CONTENT = """\
filegroup(
    name = "all_srcs",
    srcs = glob(["**/**/**"]),
    visibility = ["//visibility:public"],
)
"""

def download_spdlog():
    http_archive(
        name = "spdlog_src",
        build_file_content = _ALL_CONTENT,
        strip_prefix = "spdlog-1.10.0",
        sha256 = "7be28ff05d32a8a11cfba94381e820dd2842835f7f319f843993101bcab44b66",
        url = "https://github.com/gabime/spdlog/archive/refs/tags/v1.10.0.zip",
    )
