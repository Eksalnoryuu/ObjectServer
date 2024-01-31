load("@rules_foreign_cc//foreign_cc:defs.bzl", "boost_build")

boost_build(
    name = "system",
    bootstrap_options = ["--with-libraries=system"],
    defines = [
        "BOOST_ASIO_HAS_CO_AWAIT",
        "BOOST_ASIO_HAS_STD_COROUTINE",
    ],
    lib_source = "@boost//:all",
    out_static_libs = ["libboost_system.a"],
    user_options = ["--with-system"],
    visibility = ["//visibility:public"],
)
