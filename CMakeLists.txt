cmake_minimum_required(VERSION 3.21)
project(proj_2_bullet_hell)

set(CMAKE_CXX_STANDARD 14)


file(GLOB proj_2_bullet_hell_SRC
        "*.h"
        "*.cpp"
        )

add_executable(proj_2_bullet_hell ${proj_2_bullet_hell_SRC})

