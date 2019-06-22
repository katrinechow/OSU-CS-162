##******************************************************************************
## Program Name: Lab 8 - Searching and Sorting:  makefile
## Author: Katrine Chow
## Date: March 2, 2018
## Description: This is the makefile for the Searching and Sorting program. It 
##		recompiles if changes are made to component files. Also a clean
##		function is defined to clear out .o files after recompile.
##		This makefile is made per instructions in Professor Rooker's
##		CS 162 makefile lecture. Found at:
##		web.engr.oregonstate.edu/~rookert/cs162/03.mp4
##******************************************************************************

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g

OBJS = sort.o main.o

SRCS = sort.cpp main.cpp

HEADERS = sort.hpp

sort: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o searchsort

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o searchsort

