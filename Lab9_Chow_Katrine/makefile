##******************************************************************************
## Program Name: Lab 9 - Stack and Queue STL Containers:  makefile
## Author: Katrine Chow
## Date: March 9, 2018
## Description: This is the makefile for the containers program. It 
##		recompiles if changes are made to component files. Also a clean
##		function is defined to clear out .o files after recompile.
##		This makefile is made per instructions in Professor Rooker's
##		CS 162 makefile lecture. Found at:
##		web.engr.oregonstate.edu/~rookert/cs162/03.mp4
##******************************************************************************

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g

OBJS = buffer.o palindrome.o menu.o main.o

SRCS = buffer.cpp palindrome.cpp menu.cpp

HEADERS = buffer.hpp palindrome.hpp menu.hpp

containers: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o containers

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o containers

