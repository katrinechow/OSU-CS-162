##******************************************************************************
## Program Name: Project 2 - Zoo Tycoon:  makefile
## Author: Katrine Chow
## Date: January 30, 2018
## Description: This is the makefile for the Zoo Tycoon program zoo. It 
##		recompiles if changes are made to component files. Also a clean
##		function is defined to clear out .o files after recompile.
##		This makefile is made per instructions in Professor Rooker's
##		CS 162 makefile lecture. Found at:
##		web.engr.oregonstate.edu/~rookert/cs162/03.mp4
##******************************************************************************

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g

OBJS = animal.o tiger.o penguin.o turtle.o zoo.o bank.o menu.o main.o

SRCS = animal.cpp tiger.cpp penguin.cpp turtle.cpp zoo.cpp bank.cpp menu.cpp

HEADERS = animal.hpp tiger.hpp penguin.hpp turtle.hpp zoo.hpp bank.hpp menu.hpp

mdeterminant: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o zoo

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o zoo

