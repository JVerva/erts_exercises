cmake_minimum_required(VERSION 3.0)

project(simple_process_ex)

# Set the SystemC include and library directories
set(SYSTEMC_INCLUDE_DIR $ENV{SYSTEMC_HOME}/include)
set(SYSTEMC_LIBRARY_DIR $ENV{SYSTEMC_HOME}/lib)

# Add the executable
add_executable(simple_process_ex main.cpp simple_process_ex.cpp)

# Link against SystemC
target_include_directories(simple_process_ex PRIVATE ${SYSTEMC_INCLUDE_DIR})
target_link_libraries(simple_process_ex ${SYSTEMC_LIBRARY_DIR}/libsystemc.so)
