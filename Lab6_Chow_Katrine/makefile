##******************************************************************************
## Program Name: Lab 6 - Doubly-Linked List:  makefile
## Author: Katrine Chow
## Date: February 12, 2018
## Description: This is the makefile for the Doubly-Linked List program. It 
##		recompiles if changes are made to component files. Also a clean
##		function is defined to clear out .o files after recompile.
##		This makefile is made per instructions in Professor Rooker's
##		CS 162 makefile lecture. Found at:
##		web.engr.oregonstate.edu/~rookert/cs162/03.mp4
##******************************************************************************

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g

OBJS = node.o doublylinked.o menu.o main.o

SRCS = node.cpp doublylinked.cpp menu.cpp

HEADERS = node.hpp doublylinked.hpp menu.hpp

double: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o double

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o double

