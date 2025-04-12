FROM ubuntu:20.04

# Set noninteractive installation to avoid prompts
ENV DEBIAN_FRONTEND=noninteractive

# Install dependencies including GTest
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    g++ \
    git \
    libgtest-dev \
    && rm -rf /var/lib/apt/lists/*

# Build and install GTest from source
RUN cd /usr/src/gtest && \
    cmake CMakeLists.txt && \
    make && \
    cp lib/*.a /usr/lib

# Create app directory
WORKDIR /app

# Copy source code
COPY . .

# Build the application
RUN mkdir -p build && \
    cd build && \
    cmake .. && \
    make

# Command to run the application
ENTRYPOINT ["/app/build/radix_sort"]
CMD ["sample_input.txt"]
