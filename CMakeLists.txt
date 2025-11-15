cmake_minimum_required(VERSION 4.0)
project(buckshot_roulette C)

set(CMAKE_C_STANDARD 11)

add_executable(buckshot_roulette src/main.c
        src/include/player.h
        src/include/string.h
        src/include/shotgun.h
        src/include/game.h
        src/game.c
        src/player.c
        src/shotgun.c
        src/string.c
        src/include/dealer.h
        src/dealer.c
)
