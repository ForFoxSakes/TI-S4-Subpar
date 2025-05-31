FROM osrf/ros:noetic-desktop-full

# Gazebo en bouwtools
RUN apt-get update && apt-get install -y \
    gazebo11 \
    ros-noetic-gazebo-ros-pkgs \
    ros-noetic-gazebo-ros-control \
    libgl1-mesa-glx \
    python3-pip \
    python3-venv \
    && apt-get clean

# Python tools voor documentatie/analyse
RUN pip3 install --no-cache-dir \
    jupyterlab \
    numpy \
    pandas \
    matplotlib \
    opencv-python
