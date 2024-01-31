load("@io_bazel_rules_docker//container:container.bzl", "container_pull")

def get_image():
    container_pull(
        name = "cpp_base",
        digest = "sha256:a25ba46a36a5b6da8dda17ae1be4719f249b1130daa5672f9daca2956a25ad03",
        registry = "docker.io",
        repository = "eksal/cpp_base",
        tag = "0.0.3",
    )
