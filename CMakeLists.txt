# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.5)

# Set the project name
project (pentomino)

# Create a sources variable with a link to all cpp files to compile
file(GLOB helloworld_SRC
     "src/*.cpp"
)

# Add an executable with the above sources
add_executable(pentomino ${helloworld_SRC})

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
target_include_directories(pentomino
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)
