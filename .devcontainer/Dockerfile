# Gebruik een specifieke tag voor consistentie
FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

# Layer 1: Basis systeem updates (verandert zelden)
RUN apt-get update && apt-get upgrade -y

# Layer 2: Kleine, essentiële tools (verandert zelden)
RUN apt-get install -y --no-install-recommends \
    curl \
    wget \
    sudo \
    gnupg2 \
    lsb-release \
    git \
    vim \
    pkg-config \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# Layer 3: Build tools (gemiddelde grootte, verandert soms)
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    gdb \
    valgrind \
    clang \
    clang-format \
    clang-tidy \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# Layer 4: Libraries (groot, verandert zelden)
RUN apt-get update && apt-get install -y --no-install-recommends \
    libboost-dev \
    libprotobuf-dev \
    protobuf-compiler \
    libyaml-cpp-dev \
    libtinyxml2-dev \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# Layer 5: GUI libraries (groot, verandert zelden)
RUN apt-get update && apt-get install -y --no-install-recommends \
    libgl1-mesa-glx \
    libxrender1 \
    libxext6 \
    libx11-dev \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# Layer 6: Python basis (verandert soms)
RUN apt-get update && apt-get install -y --no-install-recommends \
    python3-pip \
    python3-venv \
    python3-dev \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# Layer 7: Gazebo repository setup (verandert zelden)
RUN curl -fsSL https://packages.osrfoundation.org/gazebo.gpg -o /usr/share/keyrings/pkgs-osrf-archive-keyring.gpg && \
    echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/pkgs-osrf-archive-keyring.gpg] http://packages.osrfoundation.org/gazebo/ubuntu-stable $(lsb_release -cs) main" > /etc/apt/sources.list.d/gazebo-stable.list

# Layer 8: Gazebo installatie (zeer groot, verandert zelden)
RUN apt-get update && apt-get install -y --no-install-recommends gz-ionic && \
    apt-get clean && rm -rf /var/lib/apt/lists/*

# Layer 9: Python packages (verandert vaak - daarom apart)
RUN pip3 install --no-cache-dir --upgrade pip && \
    pip3 install --no-cache-dir \
    jupyterlab \
    numpy \
    pandas \
    matplotlib \
    seaborn \
    scikit-learn \
    opencv-python-headless

# Werkmap (laatste, verandert niet)
WORKDIR /workspaces/subpar

CMD ["sleep", "infinity"]
