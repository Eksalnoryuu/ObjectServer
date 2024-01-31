load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

_ALL_CONTENT = """\
filegroup(
    name = "all_srcs",
    srcs = glob(["**/**/**"]),
    visibility = ["//visibility:public"],
)
"""

def download_sqlite():
    http_archive(
        name = "sqlitecpp_src",
        build_file_content = _ALL_CONTENT,
        strip_prefix = "SQLiteCpp-3.2.1",
        sha256 = "584f7c36b6b169c10c890240ea5fb36318d0ea5713c908f08201a95a93642d21",
        url = "https://github.com/SRombauts/SQLiteCpp/archive/refs/tags/3.2.1.zip",
    )
