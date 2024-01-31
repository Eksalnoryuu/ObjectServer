load("//third_party/spdlog:deps.bzl", "download_spdlog")
load("//third_party/boost:deps.bzl", "download_boost")
load("//third_party/sqlite:deps.bzl", "download_sqlite")
load("//third_party/zeromqcpp:deps.bzl", "download_zeromq")
load("//third_party/json:deps.bzl", "download_json")

def deps():
    "Load_all_third_party_rules"
    download_spdlog()
    download_boost()
    download_sqlite()
    download_zeromq()
    download_json()
