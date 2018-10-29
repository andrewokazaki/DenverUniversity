cmake_minimum_required(VERSION 3.12)
project(Homework)

set(CMAKE_CXX_STANDARD 14)

include_directories(tickTackToe)
include_directories(vigenereCipher)
include_directories(vigenereCipherTest)
include_directories(input)




add_executable(Homework
        tickTackToe/tickTackToe.cpp
        tickTackToe/tickTackToe.h
        vigenereCipher/vigenereCipher.cpp
        vigenereCipher/vigenereCipher.h
        test/vigenereCipherTest.cpp
        test/vigenereCipherTest.h
        vigenereCipher/files/input.txt
        main.cpp)
