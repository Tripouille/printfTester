FROM debian:bullseye-slim

RUN apt-get update && \
    apt-get -y upgrade && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y \
        git \
        build-essential \
        clang \
        valgrind && \
    mkdir -p /project && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /project
