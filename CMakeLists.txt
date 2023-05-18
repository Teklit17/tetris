cmake_minimum_required(VERSION 3.22)
project(tetris)
set(CMAKE_CXX_STANDARD 17)

add_executable(tetris main.cpp audio/audio.h audio/audio.cpp
        Tetraminos/Tetramino.cpp Tetraminos/Tetramino.h
        Tetraminos/I_Tetramino.cpp Tetraminos/I_Tetramino.h
        Tetraminos/L_Tetramino.cpp Tetraminos/L_Tetramino.h
        Tetraminos/Z_Tetramino.cpp Tetraminos/Z_Tetramino.h
        Tetraminos/J_Tetramino.cpp Tetraminos/J_Tetramino.h
        Tetraminos/O_Tetramino.cpp Tetraminos/O_Tetramino.h
        Tetraminos/S_Tetramino.cpp Tetraminos/S_Tetramino.h
        Tetraminos/T_Tetramino.cpp Tetraminos/T_Tetramino.h
        Board/Board.cpp Board/Board.h
        GameLogics/RandomTetramino.cpp GameLogics/RandomTetramino.h
        Menu/Menu.cpp Menu/Menu.h GameLogics/event.cpp GameLogics/event.h
        GameLogics/gameloop.cpp GameLogics/gameloop.h
        )

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/Users/Aman/ikt103g23v/project/tetris/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(C:/SFML/include)
target_link_libraries(tetris sfml-system sfml-window sfml-graphics sfml-audio sfml-network)