##******************************************************************************
## Program Name: Lab 4 - OSU Information System:  makefile
## Author: Katrine Chow
## Date: January 29, 2018
## Description: This is the makefile for the OSU Info Sys program osu. It 
##		recompiles if changes are made to component files. Also a clean
##		function is defined to clear out .o files after recompile.
##		This makefile is made per instructions in Professor Rooker's
##		CS 162 makefile lecture. Found at:
##		web.engr.oregonstate.edu/~rookert/cs162/03.mp4
##******************************************************************************

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g

OBJS = university.o building.o person.o student.o instructor.o menu.o main.o

SRCS = university.cpp building.cpp person.cpp student.cpp instructor.cpp menu.cpp

HEADERS = university.hpp building.hpp person.hpp student.hpp instructor.hpp menu.hpp

mdeterminant: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o osu

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o osu

