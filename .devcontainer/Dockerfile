FROM osrf/ros:noetic-desktop-full

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    gdb \
    git \
    curl \
    wget \
    vim \
    lsb-release \
    libtinyxml2-dev \
    clang \
    clang-format \
    clang-tidy \
    valgrind \
    libboost-all-dev \
    libprotobuf-dev \
    protobuf-compiler \
    libyaml-cpp-dev \
    pkg-config \
    libgl1-mesa-glx \
    python3-pip \
    python3-venv \
    && apt-get clean

# Python tools voor notebooks, data, en vision
RUN pip3 install --no-cache-dir \
    jupyterlab \
    numpy \
    pandas \
    matplotlib \
    seaborn \
    scikit-learn \
    opencv-python

# (optioneel) extra configuratie
WORKDIR /workspaces/subpar

CMD ["sleep", "infinity"]
