load_image() {
    local service_name="$1"
    bazel build $MODE //service/${service_name}:image.tar
    local image_path=$(bazel cquery "service/${service_name}:image.tar" \
        --output starlark \
        --starlark:expr="target.files.to_list()[0].path" \
        $MODE)
    docker load -i $image_path
}

if [ "$1" ]; then
    load_image "$1"
    exit 0
fi

load_image "object_server"