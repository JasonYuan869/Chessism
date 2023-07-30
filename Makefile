# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /u3/rz6zhang/cs247/chessism

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /u3/rz6zhang/cs247/chessism

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /u3/rz6zhang/cs247/chessism/CMakeFiles /u3/rz6zhang/cs247/chessism//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /u3/rz6zhang/cs247/chessism/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named chessism

# Build rule for target.
chessism: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 chessism
.PHONY : chessism

# fast build rule for target.
chessism/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/build
.PHONY : chessism/fast

src/BoardState.o: src/BoardState.cc.o
.PHONY : src/BoardState.o

# target to build an object file
src/BoardState.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/BoardState.cc.o
.PHONY : src/BoardState.cc.o

src/BoardState.i: src/BoardState.cc.i
.PHONY : src/BoardState.i

# target to preprocess a source file
src/BoardState.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/BoardState.cc.i
.PHONY : src/BoardState.cc.i

src/BoardState.s: src/BoardState.cc.s
.PHONY : src/BoardState.s

# target to generate assembly for a file
src/BoardState.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/BoardState.cc.s
.PHONY : src/BoardState.cc.s

src/Game.o: src/Game.cc.o
.PHONY : src/Game.o

# target to build an object file
src/Game.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/Game.cc.o
.PHONY : src/Game.cc.o

src/Game.i: src/Game.cc.i
.PHONY : src/Game.i

# target to preprocess a source file
src/Game.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/Game.cc.i
.PHONY : src/Game.cc.i

src/Game.s: src/Game.cc.s
.PHONY : src/Game.s

# target to generate assembly for a file
src/Game.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/Game.cc.s
.PHONY : src/Game.cc.s

src/Graphical.o: src/Graphical.cc.o
.PHONY : src/Graphical.o

# target to build an object file
src/Graphical.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/Graphical.cc.o
.PHONY : src/Graphical.cc.o

src/Graphical.i: src/Graphical.cc.i
.PHONY : src/Graphical.i

# target to preprocess a source file
src/Graphical.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/Graphical.cc.i
.PHONY : src/Graphical.cc.i

src/Graphical.s: src/Graphical.cc.s
.PHONY : src/Graphical.s

# target to generate assembly for a file
src/Graphical.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/Graphical.cc.s
.PHONY : src/Graphical.cc.s

src/GraphicalTile.o: src/GraphicalTile.cc.o
.PHONY : src/GraphicalTile.o

# target to build an object file
src/GraphicalTile.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/GraphicalTile.cc.o
.PHONY : src/GraphicalTile.cc.o

src/GraphicalTile.i: src/GraphicalTile.cc.i
.PHONY : src/GraphicalTile.i

# target to preprocess a source file
src/GraphicalTile.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/GraphicalTile.cc.i
.PHONY : src/GraphicalTile.cc.i

src/GraphicalTile.s: src/GraphicalTile.cc.s
.PHONY : src/GraphicalTile.s

# target to generate assembly for a file
src/GraphicalTile.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/GraphicalTile.cc.s
.PHONY : src/GraphicalTile.cc.s

src/Move.o: src/Move.cc.o
.PHONY : src/Move.o

# target to build an object file
src/Move.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/Move.cc.o
.PHONY : src/Move.cc.o

src/Move.i: src/Move.cc.i
.PHONY : src/Move.i

# target to preprocess a source file
src/Move.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/Move.cc.i
.PHONY : src/Move.cc.i

src/Move.s: src/Move.cc.s
.PHONY : src/Move.s

# target to generate assembly for a file
src/Move.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/Move.cc.s
.PHONY : src/Move.cc.s

src/Observer.o: src/Observer.cc.o
.PHONY : src/Observer.o

# target to build an object file
src/Observer.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/Observer.cc.o
.PHONY : src/Observer.cc.o

src/Observer.i: src/Observer.cc.i
.PHONY : src/Observer.i

# target to preprocess a source file
src/Observer.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/Observer.cc.i
.PHONY : src/Observer.cc.i

src/Observer.s: src/Observer.cc.s
.PHONY : src/Observer.s

# target to generate assembly for a file
src/Observer.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/Observer.cc.s
.PHONY : src/Observer.cc.s

src/PawnPiece.o: src/PawnPiece.cc.o
.PHONY : src/PawnPiece.o

# target to build an object file
src/PawnPiece.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/PawnPiece.cc.o
.PHONY : src/PawnPiece.cc.o

src/PawnPiece.i: src/PawnPiece.cc.i
.PHONY : src/PawnPiece.i

# target to preprocess a source file
src/PawnPiece.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/PawnPiece.cc.i
.PHONY : src/PawnPiece.cc.i

src/PawnPiece.s: src/PawnPiece.cc.s
.PHONY : src/PawnPiece.s

# target to generate assembly for a file
src/PawnPiece.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/PawnPiece.cc.s
.PHONY : src/PawnPiece.cc.s

src/Subject.o: src/Subject.cc.o
.PHONY : src/Subject.o

# target to build an object file
src/Subject.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/Subject.cc.o
.PHONY : src/Subject.cc.o

src/Subject.i: src/Subject.cc.i
.PHONY : src/Subject.i

# target to preprocess a source file
src/Subject.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/Subject.cc.i
.PHONY : src/Subject.cc.i

src/Subject.s: src/Subject.cc.s
.PHONY : src/Subject.s

# target to generate assembly for a file
src/Subject.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/Subject.cc.s
.PHONY : src/Subject.cc.s

src/Terminal.o: src/Terminal.cc.o
.PHONY : src/Terminal.o

# target to build an object file
src/Terminal.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/Terminal.cc.o
.PHONY : src/Terminal.cc.o

src/Terminal.i: src/Terminal.cc.i
.PHONY : src/Terminal.i

# target to preprocess a source file
src/Terminal.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/Terminal.cc.i
.PHONY : src/Terminal.cc.i

src/Terminal.s: src/Terminal.cc.s
.PHONY : src/Terminal.s

# target to generate assembly for a file
src/Terminal.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/Terminal.cc.s
.PHONY : src/Terminal.cc.s

src/main.o: src/main.cc.o
.PHONY : src/main.o

# target to build an object file
src/main.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/main.cc.o
.PHONY : src/main.cc.o

src/main.i: src/main.cc.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/main.cc.i
.PHONY : src/main.cc.i

src/main.s: src/main.cc.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/main.cc.s
.PHONY : src/main.cc.s

src/pieces/BishopPiece.o: src/pieces/BishopPiece.cc.o
.PHONY : src/pieces/BishopPiece.o

# target to build an object file
src/pieces/BishopPiece.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/pieces/BishopPiece.cc.o
.PHONY : src/pieces/BishopPiece.cc.o

src/pieces/BishopPiece.i: src/pieces/BishopPiece.cc.i
.PHONY : src/pieces/BishopPiece.i

# target to preprocess a source file
src/pieces/BishopPiece.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/pieces/BishopPiece.cc.i
.PHONY : src/pieces/BishopPiece.cc.i

src/pieces/BishopPiece.s: src/pieces/BishopPiece.cc.s
.PHONY : src/pieces/BishopPiece.s

# target to generate assembly for a file
src/pieces/BishopPiece.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/pieces/BishopPiece.cc.s
.PHONY : src/pieces/BishopPiece.cc.s

src/pieces/KingPiece.o: src/pieces/KingPiece.cc.o
.PHONY : src/pieces/KingPiece.o

# target to build an object file
src/pieces/KingPiece.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/pieces/KingPiece.cc.o
.PHONY : src/pieces/KingPiece.cc.o

src/pieces/KingPiece.i: src/pieces/KingPiece.cc.i
.PHONY : src/pieces/KingPiece.i

# target to preprocess a source file
src/pieces/KingPiece.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/pieces/KingPiece.cc.i
.PHONY : src/pieces/KingPiece.cc.i

src/pieces/KingPiece.s: src/pieces/KingPiece.cc.s
.PHONY : src/pieces/KingPiece.s

# target to generate assembly for a file
src/pieces/KingPiece.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/pieces/KingPiece.cc.s
.PHONY : src/pieces/KingPiece.cc.s

src/pieces/KnightPiece.o: src/pieces/KnightPiece.cc.o
.PHONY : src/pieces/KnightPiece.o

# target to build an object file
src/pieces/KnightPiece.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/pieces/KnightPiece.cc.o
.PHONY : src/pieces/KnightPiece.cc.o

src/pieces/KnightPiece.i: src/pieces/KnightPiece.cc.i
.PHONY : src/pieces/KnightPiece.i

# target to preprocess a source file
src/pieces/KnightPiece.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/pieces/KnightPiece.cc.i
.PHONY : src/pieces/KnightPiece.cc.i

src/pieces/KnightPiece.s: src/pieces/KnightPiece.cc.s
.PHONY : src/pieces/KnightPiece.s

# target to generate assembly for a file
src/pieces/KnightPiece.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/pieces/KnightPiece.cc.s
.PHONY : src/pieces/KnightPiece.cc.s

src/pieces/Piece.o: src/pieces/Piece.cc.o
.PHONY : src/pieces/Piece.o

# target to build an object file
src/pieces/Piece.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/pieces/Piece.cc.o
.PHONY : src/pieces/Piece.cc.o

src/pieces/Piece.i: src/pieces/Piece.cc.i
.PHONY : src/pieces/Piece.i

# target to preprocess a source file
src/pieces/Piece.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/pieces/Piece.cc.i
.PHONY : src/pieces/Piece.cc.i

src/pieces/Piece.s: src/pieces/Piece.cc.s
.PHONY : src/pieces/Piece.s

# target to generate assembly for a file
src/pieces/Piece.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/pieces/Piece.cc.s
.PHONY : src/pieces/Piece.cc.s

src/pieces/QueenPiece.o: src/pieces/QueenPiece.cc.o
.PHONY : src/pieces/QueenPiece.o

# target to build an object file
src/pieces/QueenPiece.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/pieces/QueenPiece.cc.o
.PHONY : src/pieces/QueenPiece.cc.o

src/pieces/QueenPiece.i: src/pieces/QueenPiece.cc.i
.PHONY : src/pieces/QueenPiece.i

# target to preprocess a source file
src/pieces/QueenPiece.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/pieces/QueenPiece.cc.i
.PHONY : src/pieces/QueenPiece.cc.i

src/pieces/QueenPiece.s: src/pieces/QueenPiece.cc.s
.PHONY : src/pieces/QueenPiece.s

# target to generate assembly for a file
src/pieces/QueenPiece.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/pieces/QueenPiece.cc.s
.PHONY : src/pieces/QueenPiece.cc.s

src/pieces/RookPiece.o: src/pieces/RookPiece.cc.o
.PHONY : src/pieces/RookPiece.o

# target to build an object file
src/pieces/RookPiece.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/pieces/RookPiece.cc.o
.PHONY : src/pieces/RookPiece.cc.o

src/pieces/RookPiece.i: src/pieces/RookPiece.cc.i
.PHONY : src/pieces/RookPiece.i

# target to preprocess a source file
src/pieces/RookPiece.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/pieces/RookPiece.cc.i
.PHONY : src/pieces/RookPiece.cc.i

src/pieces/RookPiece.s: src/pieces/RookPiece.cc.s
.PHONY : src/pieces/RookPiece.s

# target to generate assembly for a file
src/pieces/RookPiece.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/pieces/RookPiece.cc.s
.PHONY : src/pieces/RookPiece.cc.s

src/players/ComputerPlayer1.o: src/players/ComputerPlayer1.cc.o
.PHONY : src/players/ComputerPlayer1.o

# target to build an object file
src/players/ComputerPlayer1.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/players/ComputerPlayer1.cc.o
.PHONY : src/players/ComputerPlayer1.cc.o

src/players/ComputerPlayer1.i: src/players/ComputerPlayer1.cc.i
.PHONY : src/players/ComputerPlayer1.i

# target to preprocess a source file
src/players/ComputerPlayer1.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/players/ComputerPlayer1.cc.i
.PHONY : src/players/ComputerPlayer1.cc.i

src/players/ComputerPlayer1.s: src/players/ComputerPlayer1.cc.s
.PHONY : src/players/ComputerPlayer1.s

# target to generate assembly for a file
src/players/ComputerPlayer1.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/players/ComputerPlayer1.cc.s
.PHONY : src/players/ComputerPlayer1.cc.s

src/players/ComputerPlayer2.o: src/players/ComputerPlayer2.cc.o
.PHONY : src/players/ComputerPlayer2.o

# target to build an object file
src/players/ComputerPlayer2.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/players/ComputerPlayer2.cc.o
.PHONY : src/players/ComputerPlayer2.cc.o

src/players/ComputerPlayer2.i: src/players/ComputerPlayer2.cc.i
.PHONY : src/players/ComputerPlayer2.i

# target to preprocess a source file
src/players/ComputerPlayer2.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/players/ComputerPlayer2.cc.i
.PHONY : src/players/ComputerPlayer2.cc.i

src/players/ComputerPlayer2.s: src/players/ComputerPlayer2.cc.s
.PHONY : src/players/ComputerPlayer2.s

# target to generate assembly for a file
src/players/ComputerPlayer2.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/players/ComputerPlayer2.cc.s
.PHONY : src/players/ComputerPlayer2.cc.s

src/players/ComputerPlayer3.o: src/players/ComputerPlayer3.cc.o
.PHONY : src/players/ComputerPlayer3.o

# target to build an object file
src/players/ComputerPlayer3.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/players/ComputerPlayer3.cc.o
.PHONY : src/players/ComputerPlayer3.cc.o

src/players/ComputerPlayer3.i: src/players/ComputerPlayer3.cc.i
.PHONY : src/players/ComputerPlayer3.i

# target to preprocess a source file
src/players/ComputerPlayer3.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/players/ComputerPlayer3.cc.i
.PHONY : src/players/ComputerPlayer3.cc.i

src/players/ComputerPlayer3.s: src/players/ComputerPlayer3.cc.s
.PHONY : src/players/ComputerPlayer3.s

# target to generate assembly for a file
src/players/ComputerPlayer3.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/players/ComputerPlayer3.cc.s
.PHONY : src/players/ComputerPlayer3.cc.s

src/players/ComputerPlayer4.o: src/players/ComputerPlayer4.cc.o
.PHONY : src/players/ComputerPlayer4.o

# target to build an object file
src/players/ComputerPlayer4.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/players/ComputerPlayer4.cc.o
.PHONY : src/players/ComputerPlayer4.cc.o

src/players/ComputerPlayer4.i: src/players/ComputerPlayer4.cc.i
.PHONY : src/players/ComputerPlayer4.i

# target to preprocess a source file
src/players/ComputerPlayer4.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/players/ComputerPlayer4.cc.i
.PHONY : src/players/ComputerPlayer4.cc.i

src/players/ComputerPlayer4.s: src/players/ComputerPlayer4.cc.s
.PHONY : src/players/ComputerPlayer4.s

# target to generate assembly for a file
src/players/ComputerPlayer4.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/players/ComputerPlayer4.cc.s
.PHONY : src/players/ComputerPlayer4.cc.s

src/players/HumanPlayer.o: src/players/HumanPlayer.cc.o
.PHONY : src/players/HumanPlayer.o

# target to build an object file
src/players/HumanPlayer.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/players/HumanPlayer.cc.o
.PHONY : src/players/HumanPlayer.cc.o

src/players/HumanPlayer.i: src/players/HumanPlayer.cc.i
.PHONY : src/players/HumanPlayer.i

# target to preprocess a source file
src/players/HumanPlayer.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/players/HumanPlayer.cc.i
.PHONY : src/players/HumanPlayer.cc.i

src/players/HumanPlayer.s: src/players/HumanPlayer.cc.s
.PHONY : src/players/HumanPlayer.s

# target to generate assembly for a file
src/players/HumanPlayer.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/players/HumanPlayer.cc.s
.PHONY : src/players/HumanPlayer.cc.s

src/players/Player.o: src/players/Player.cc.o
.PHONY : src/players/Player.o

# target to build an object file
src/players/Player.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/players/Player.cc.o
.PHONY : src/players/Player.cc.o

src/players/Player.i: src/players/Player.cc.i
.PHONY : src/players/Player.i

# target to preprocess a source file
src/players/Player.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/players/Player.cc.i
.PHONY : src/players/Player.cc.i

src/players/Player.s: src/players/Player.cc.s
.PHONY : src/players/Player.s

# target to generate assembly for a file
src/players/Player.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/chessism.dir/build.make CMakeFiles/chessism.dir/src/players/Player.cc.s
.PHONY : src/players/Player.cc.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... chessism"
	@echo "... src/BoardState.o"
	@echo "... src/BoardState.i"
	@echo "... src/BoardState.s"
	@echo "... src/Game.o"
	@echo "... src/Game.i"
	@echo "... src/Game.s"
	@echo "... src/Graphical.o"
	@echo "... src/Graphical.i"
	@echo "... src/Graphical.s"
	@echo "... src/GraphicalTile.o"
	@echo "... src/GraphicalTile.i"
	@echo "... src/GraphicalTile.s"
	@echo "... src/Move.o"
	@echo "... src/Move.i"
	@echo "... src/Move.s"
	@echo "... src/Observer.o"
	@echo "... src/Observer.i"
	@echo "... src/Observer.s"
	@echo "... src/PawnPiece.o"
	@echo "... src/PawnPiece.i"
	@echo "... src/PawnPiece.s"
	@echo "... src/Subject.o"
	@echo "... src/Subject.i"
	@echo "... src/Subject.s"
	@echo "... src/Terminal.o"
	@echo "... src/Terminal.i"
	@echo "... src/Terminal.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/pieces/BishopPiece.o"
	@echo "... src/pieces/BishopPiece.i"
	@echo "... src/pieces/BishopPiece.s"
	@echo "... src/pieces/KingPiece.o"
	@echo "... src/pieces/KingPiece.i"
	@echo "... src/pieces/KingPiece.s"
	@echo "... src/pieces/KnightPiece.o"
	@echo "... src/pieces/KnightPiece.i"
	@echo "... src/pieces/KnightPiece.s"
	@echo "... src/pieces/Piece.o"
	@echo "... src/pieces/Piece.i"
	@echo "... src/pieces/Piece.s"
	@echo "... src/pieces/QueenPiece.o"
	@echo "... src/pieces/QueenPiece.i"
	@echo "... src/pieces/QueenPiece.s"
	@echo "... src/pieces/RookPiece.o"
	@echo "... src/pieces/RookPiece.i"
	@echo "... src/pieces/RookPiece.s"
	@echo "... src/players/ComputerPlayer1.o"
	@echo "... src/players/ComputerPlayer1.i"
	@echo "... src/players/ComputerPlayer1.s"
	@echo "... src/players/ComputerPlayer2.o"
	@echo "... src/players/ComputerPlayer2.i"
	@echo "... src/players/ComputerPlayer2.s"
	@echo "... src/players/ComputerPlayer3.o"
	@echo "... src/players/ComputerPlayer3.i"
	@echo "... src/players/ComputerPlayer3.s"
	@echo "... src/players/ComputerPlayer4.o"
	@echo "... src/players/ComputerPlayer4.i"
	@echo "... src/players/ComputerPlayer4.s"
	@echo "... src/players/HumanPlayer.o"
	@echo "... src/players/HumanPlayer.i"
	@echo "... src/players/HumanPlayer.s"
	@echo "... src/players/Player.o"
	@echo "... src/players/Player.i"
	@echo "... src/players/Player.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

