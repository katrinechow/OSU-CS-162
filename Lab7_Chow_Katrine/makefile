##******************************************************************************
## Program Name: Lab 7 - Circular Linked List:  makefile
## Author: Katrine Chow
## Date: February 22, 2018
## Description: This is the makefile for the Circular Linked List program. It 
##		recompiles if changes are made to component files. Also a clean
##		function is defined to clear out .o files after recompile.
##		This makefile is made per instructions in Professor Rooker's
##		CS 162 makefile lecture. Found at:
##		web.engr.oregonstate.edu/~rookert/cs162/03.mp4
##******************************************************************************

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g

OBJS = queue.o menu.o main.o

SRCS = queue.cpp menu.cpp

HEADERS = node.hpp queue.hpp menu.hpp

circular: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o circular

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o circular

