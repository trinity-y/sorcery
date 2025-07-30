#Generalized Makefile (C++ specific)
CXX=g++ #special Makefile variable indicating which compiler to use
CXXFLAGS= -std=c++14 -Wall -g -MMD #MMD auto generates dependencies
EXEC=sorcery
CCFILES=$(wildcard *.cc */*.cc */*/*.cc)
OBJECTS=${CCFILES:.cc=.o}
DEPENDS=${CCFILES:.cc=.d}

${EXEC}:${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean
clean:
	rm ${EXEC} ${OBJECTS} ${DEPENDS}

