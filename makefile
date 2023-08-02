CXX=g++
CXXFLAGS=-std=c++14 -Wall -g -O3 -MMD
LDFLAGS=-lX11
EXEC=chess
CCFILES=$(wildcard *.cc)
OBJECTS=${CCFILES:.cc=.o}
DEPENDS=${CCFILES:.cc=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC} ${LDFLAGS}
-include ${DEPENDS}

clean:
	rm *.d *.o ${EXEC}
.PHONY: clean