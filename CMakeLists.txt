cmake_minimum_required(VERSION 3.22)
project(chessism)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)


# For X11
find_package(X11 REQUIRED)
add_executable(chessism
        src/main.cc
        src/pieces/BishopPiece.cc
        src/BoardState.cc
        src/players/ComputerPlayer1.cc
        src/players/ComputerPlayer2.cc
        src/players/ComputerPlayer3.cc
        src/players/ComputerPlayer4.cc
        src/Game.cc
        src/Graphical.cc
        src/players/HumanPlayer.cc
        src/pieces/KingPiece.cc
        src/pieces/KnightPiece.cc
        src/Move.cc
        src/pieces/PawnPiece.cc
        src/pieces/Piece.cc
        src/pieces/QueenPiece.cc
        src/pieces/RookPiece.cc
        src/Terminal.cc
        src/players/Player.cc
        src/Subject.cc
        src/Observer.cc
        src/GraphicalTile.cc)

include_directories(${X11_INCLUDE_DIR})
link_directories(${X11_LIBRARIES})
target_link_libraries(chessism ${X11_LIBRARIES})