##******************************************************************************
## Program Name: Project 1: Langton's Ant - makefile
## Author: Katrine Chow
## Date: January 10, 2018
## Description: This is the makefile for the Langton's Ant simulation program
##              langtonsant. It recompiles if changes are made to component
##              files. Also a clean function is defined to clear out .o files
##              after recompile.
##		This makefile is made per instructions in Professor Rooker's
##		CS 162 makefile lecture. Found at:
##		web.engr.oregonstate.edu/~rookert/cs162/03.mp4
##******************************************************************************

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g

OBJS = menu.o board.o ant.o main.o

SRCS = menu.cpp board.cpp ant.cpp main.cpp

HEADERS = menu.hpp board.hpp ant.hpp

mdeterminant: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o langtonsant

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o langtonsant

