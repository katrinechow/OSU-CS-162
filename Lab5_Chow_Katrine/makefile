##******************************************************************************
## Program Name: Lab 5 - Recursive Functions:  makefile
## Author: Katrine Chow
## Date: February 7, 2018
## Description: This is the makefile for the Recursive Functions program. It 
##		recompiles if changes are made to component files. Also a clean
##		function is defined to clear out .o files after recompile.
##		This makefile is made per instructions in Professor Rooker's
##		CS 162 makefile lecture. Found at:
##		web.engr.oregonstate.edu/~rookert/cs162/03.mp4
##******************************************************************************

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g

OBJS = recursion.o menu.o main.o

SRCS = recursion.cpp menu.cpp menu.cpp

HEADERS = recursion.hpp menu.hpp

mdeterminant: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o recursion

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o recursion

