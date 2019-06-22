##******************************************************************************
## Program Name: Lab 1 Matrix Calculator - makefile
## Author: Katrine Chow
## Date: January 10, 2018
## Description: This is the makefile for the Matrix Calculator program
##              mdeterminant. It recompiles if changes are made to component
##              files. Also a clean function is defined to clear out .o files
##              after recompile.
##		This makefile is made per instructions in Professor Rooker's
##		CS 162 makefile lecture. Found at:
##		web.engr.oregonstate.edu/~rookert/cs162/03.mp4
##******************************************************************************

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g

OBJS = matrix.o determinant.o main.o

SRCS = matrix.cpp determinant.cpp main.cpp

HEADERS = matrix.hpp determinant.hpp

mdeterminant: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o mdeterminant

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o mdeterminant

