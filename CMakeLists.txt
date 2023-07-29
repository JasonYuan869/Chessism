cmake_minimum_required(VERSION 3.22)
project(chessism)

set(CMAKE_CXX_STANDARD 14)

# For X11
find_package(X11 REQUIRED)
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
        src/Terminal.cc
        src/Player.cc
        src/Subject.cc
        src/Observer.cc
        src/GraphicalTile.cc)

include_directories(${X11_INCLUDE_DIR})
link_directories(${X11_LIBRARIES})
target_link_libraries(chessism ${X11_LIBRARIES})