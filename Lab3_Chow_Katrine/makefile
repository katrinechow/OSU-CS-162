##******************************************************************************
## Program Name: Lab 3 War Game (dice):  makefile
## Author: Katrine Chow
## Date: January 27, 2018
## Description: This is the makefile for the War Game program war. It 
##		recompiles if changes are made to component files. Also a clean
##		function is defined to clear out .o files after recompile.
##		This makefile is made per instructions in Professor Rooker's
##		CS 162 makefile lecture. Found at:
##		web.engr.oregonstate.edu/~rookert/cs162/03.mp4
##******************************************************************************

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g

OBJS = die.o loadeddie.o game.o menu.o main.o

SRCS = die.cpp loadeddie.cpp game.cpp menu.cpp

HEADERS = die.hpp loadeddie.hpp game.hpp menu.hpp

mdeterminant: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o war

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o war

