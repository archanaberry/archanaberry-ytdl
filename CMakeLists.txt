cmake_minimum_required(VERSION 3.10)
project(ytdl)

# Add C++ compiler flags
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Add executable
add_executable(ytdl
        archanaberry-youtube/archanaberry-ytdl.cpp
        archanaberry-youtube/constant.cpp
        archanaberry-youtube/index.cpp
        ytdl.cpp
        )

# Include directories
target_include_directories(ytdl PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/archanaberry-youtube)

# Set output directories
set_target_properties(ytdl PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
        )

# Install header files
install(FILES archanaberry-youtube/constant.hpp archanaberry-youtube/index.hpp archanaberry-youtube/tinyspawn.hpp DESTINATION include/archanaberry-ytdl)

# Link with libcurl
target_link_libraries(ytdl ${CURL_LIBRARIES})
