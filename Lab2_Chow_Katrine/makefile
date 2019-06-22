##******************************************************************************
## Program Name: Lab 2: File I/O - makefile
## Author: Katrine Chow
## Date: January 19, 2018
## Description: This is the makefile for the File I/O program fileio. It 
##		recompiles if changes are made to component files. Also a clean
##		function is defined to clear out .o files after recompile.
##		This makefile is made per instructions in Professor Rooker's
##		CS 162 makefile lecture. Found at:
##		web.engr.oregonstate.edu/~rookert/cs162/03.mp4
##******************************************************************************

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g

OBJS = letters.o main.o

SRCS = letters.cpp main.cpp

HEADERS = letters.hpp

mdeterminant: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o fileio

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o fileio

