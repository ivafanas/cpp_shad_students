FROM ubuntu:24.04

ARG DEBIAN_FRONTEND=noninteractive

ARG apt_archive="http://archive.ubuntu.com"
RUN sed -i "s|http://archive.ubuntu.com|${apt_archive}|g" /etc/apt/sources.list \
    && groupadd -r testuser --gid=101 \
    && useradd -r -g testuser --uid=101 --home-dir=/var/lib/testuser --shell=/bin/bash testuser \
    && apt-get update \
    && apt-get upgrade -yq \
    && apt-get install --yes --no-install-recommends \
          ca-certificates \
          wget \
          git \
          gcc-14 \
          g++-14 \
          clang-18 \
          libc++-18-dev \
          libc++abi-18-dev \
          libclang-rt-18-dev \
          clang-format-18 \
          clang-tidy-18 \
          cmake \
          cppcheck \
          ninja-build \
    && apt-get clean \
    && rm -rf \
        /var/lib/apt/lists/* \
        /var/cache/debconf \
        /tmp/* \
    && cd ~ \
    && git clone https://github.com/google/googletest.git \
    && cd googletest && mkdir build && cd build \
    && CC=clang-18 CXX=clang++-18 cmake -G Ninja -DCMAKE_BUILD_TYPE=Release .. \
    && cmake --build . --target install \
    && cd .. && cd .. && rm -rf googletest

