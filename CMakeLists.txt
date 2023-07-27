cmake_minimum_required(VERSION 3.22)
project(chessism)

set(CMAKE_CXX_STANDARD 14)

# For GTKMM
find_package(PkgConfig REQUIRED)
pkg_check_modules(gtkmm REQUIRED gtkmm-3.0)

add_executable(chessism
        src/main.cc
        src/BishopPiece.cc
        src/BoardState.cc
        src/ComputerPlayer1.cc
        src/ComputerPlayer2.cc
        src/ComputerPlayer3.cc
        src/ComputerPlayer4.cc
        src/Game.cc
        src/Graphical.cc
        src/HumanPlayer.cc
        src/KingPiece.cc
        src/KnightPiece.cc
        src/Move.cc
        src/PawnPiece.cc
        src/Piece.cc
        src/QueenPiece.cc
        src/RookPiece.cc
        src/Terminal.cc)

target_link_libraries(chessism ${gtkmm_LIBRARIES})
target_include_directories(chessism PUBLIC ${gtkmm_INCLUDE_DIRS})
target_compile_options(chessism PUBLIC ${gtkmm_CFLAGS_OTHER})