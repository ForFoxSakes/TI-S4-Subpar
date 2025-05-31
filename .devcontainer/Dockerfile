FROM ubuntu:jammy


ENV DEBIAN_FRONTEND=noninteractive

# Basis tools
RUN apt-get update && apt-get install -y \
    curl \
    wget \
    sudo \
    gnupg2 \
    lsb-release \
    git \
    build-essential \
    cmake \
    gdb \
    valgrind \
    clang \
    clang-format \
    clang-tidy \
    libboost-all-dev \
    libprotobuf-dev \
    protobuf-compiler \
    libyaml-cpp-dev \
    libtinyxml2-dev \
    pkg-config \
    libgl1-mesa-glx \
    libxrender1 \
    libxext6 \
    libx11-dev \
    vim \
    python3-pip \
    python3-venv \
    && apt-get clean

# Gazebo installatie (volgens handleiding)
RUN curl -fsSL https://packages.osrfoundation.org/gazebo.gpg -o /usr/share/keyrings/pkgs-osrf-archive-keyring.gpg
RUN echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/pkgs-osrf-archive-keyring.gpg] http://packages.osrfoundation.org/gazebo/ubuntu-stable $(lsb_release -cs) main" > /etc/apt/sources.list.d/gazebo-stable.list
RUN apt-get update && apt-get install -y gz-ionic

# Python tools voor notebooks en vision
RUN pip3 install --no-cache-dir \
    jupyterlab \
    numpy \
    pandas \
    matplotlib \
    seaborn \
    scikit-learn \
    opencv-python

# Werkmap instellen
WORKDIR /workspaces/subpar

CMD ["sleep", "infinity"]
