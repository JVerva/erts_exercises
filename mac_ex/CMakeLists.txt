cmake_minimum_required(VERSION 3.0)

project(mac)

# Set the SystemC include and library directories
set(SYSTEMC_INCLUDE_DIR $ENV{SYSTEMC_HOME}/include)
set(SYSTEMC_LIBRARY_DIR $ENV{SYSTEMC_HOME}/lib)

# Add the executable
add_executable(mac src/main.cpp src/mac.cpp src/stimulus.cpp)

# Link against SystemC
target_include_directories(mac PRIVATE ${SYSTEMC_INCLUDE_DIR})
target_link_libraries(mac ${SYSTEMC_LIBRARY_DIR}/libsystemc.so)