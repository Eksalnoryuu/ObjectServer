# Introduction

This repo is simple server to hold .obj files in sqlite server.

# How to run it ?

Install Bazel on ur PC 

<code> sudo apt install bazel </code>

Install also this dependecies

```bash
sudo apt-get update
sudo apt-get install libzmq3-dev libsqlite3-dev libzmqpp-dev
```

Link to Bazel site <code> https://bazel.build/ </code>

After that you should run this command in the repo <code> bazel build //...</code>

If everything works run this command to run the server <code> bazel run //service/object_server:object_server </code>

To run fronted App to add files to database run <code> python3 frontend.py</code> in the folder where `frontend.py` exist.

To run server in docker use the `./script/build.sh` after the docker is created run the docker-compose in deploy folder `docker-compose up`