##******************************************************************************
## Program Name: Final Project - Text-based Game:  makefile
## Author: Katrine Chow
## Date: March 15, 2018
## Description: This is the makefile for the spectrum program. The makefile 
##		recompiles if changes are made to component files. Also a clean
##		function is defined to clear out .o files after recompile.
##		This makefile is made per instructions in Professor Rooker's
##		CS 162 makefile lecture. Found at:
##		web.engr.oregonstate.edu/~rookert/cs162/03.mp4
##******************************************************************************

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g

OBJS = menu.o game.o player.o space.o mainhall.o kitchen.o gym.o pond.o attic.o study.o main.o

SRCS = menu.cpp game.cpp player.cpp space.cpp mainhall.cpp kitchen.cpp gym.cpp pond.cpp attic.hpp study.cpp main.cpp

HEADERS = menu.hpp game.hpp player.hpp space.hpp mainhall.hpp kitchen.hpp gym.hpp pond.hpp attic.hpp study.hpp

spectrum: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o spectrum

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o spectrum

