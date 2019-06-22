##******************************************************************************
## Program Name: Project 3 - Fantasy Combat Game:  makefile
## Author: Katrine Chow
## Date: February 12, 2018
## Description: This is the makefile for the Fantasy Combat game combat. It 
##		recompiles if changes are made to component files. Also a clean
##		function is defined to clear out .o files after recompile.
##		This makefile is made per instructions in Professor Rooker's
##		CS 162 makefile lecture. Found at:
##		web.engr.oregonstate.edu/~rookert/cs162/03.mp4
##******************************************************************************

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g

OBJS = character.o vampire.o barbarian.o bluemen.o medusa.o harrypotter.o die.o  menu.o main.o

SRCS = character.cpp vampire.cpp barbarian.cpp bluemen.cpp medusa.cpp harrypotter.cpp menu.cpp die.cpp

HEADERS = character.hpp vampire.hpp barbarian.hpp bluemen.hpp medusa.hpp harrypotter.hpp menu.hpp die.hpp

combat: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o combat

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o combat

