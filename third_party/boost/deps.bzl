load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

all_content = """filegroup(name = "all", srcs = glob(["**"]), visibility = ["//visibility:public"])"""

def download_boost():
    http_archive(
        name = "boost",
        build_file_content = all_content,
        strip_prefix = "boost_1_79_0",
        sha256 = "273f1be93238a068aba4f9735a4a2b003019af067b9c183ed227780b8f36062c",
        urls = ["https://boostorg.jfrog.io/artifactory/main/release/1.79.0/source/boost_1_79_0.tar.gz"],
    )
