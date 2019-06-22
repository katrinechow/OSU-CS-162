##******************************************************************************
## Program Name: Lab 10 - Recursive and Iterative Functions:  makefile
## Author: Katrine Chow
## Date: March 12, 2018
## Description: This is the makefile for the measure program. It 
##		recompiles if changes are made to component files. Also a clean
##		function is defined to clear out .o files after recompile.
##		This makefile is made per instructions in Professor Rooker's
##		CS 162 makefile lecture. Found at:
##		web.engr.oregonstate.edu/~rookert/cs162/03.mp4
##******************************************************************************

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g

OBJS = iteration.o recursion.o main.o

SRCS = iteration.cpp recursion.cpp

HEADERS = iteration.hpp recursion.hpp

measure: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o measure

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o measure

