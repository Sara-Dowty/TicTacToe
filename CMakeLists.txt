cmake_minimum_required(VERSION 3.29)
project(tictactoeSource_SaraDowty)

set(CMAKE_CXX_STANDARD 20)
set(CMake_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
add_compile_options(-msse4.2)
add_executable(tictactoeSource_SaraDowty main.cpp
        Mark.h
        Square.cpp
        Square.h
        test_Square.cpp
        test_Square.h
        Row.cpp
        Row.h
        testRow.cpp
        testRow.h
        Grid.cpp
        Grid.h
        Player.cpp
        Player.h
        testPlayer.cpp
        testPlayer.h
        GridView.cpp
        GridView.h
        TicTacToe.cpp
        TicTacToe.h
        GridModel.cpp
        GridModel.h
)
