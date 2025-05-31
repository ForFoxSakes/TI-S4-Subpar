FROM osrf/ros:noetic-desktop-full

RUN apt-get update && apt-get install -y \
    git \
    curl \
    wget \
    nano \
    unzip \
    gazebo11 \
    ros-noetic-gazebo-ros-pkgs \
    ros-noetic-gazebo-ros-control \
    libgl1-mesa-glx \
    python3-pip \
    python3-venv \
    && apt-get clean

RUN pip3 install --no-cache-dir \
    jupyterlab \
    numpy \
    pandas \
    matplotlib \
    opencv-python
