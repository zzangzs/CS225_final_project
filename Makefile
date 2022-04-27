EXE = airports
TEST = test

EXE_OBJ = main.o
OBJS = main.o Airport.o Readfile.o Graph.o cs225/PNG.o cs225/HSLAPixel.o 

# Use the CS 225 Makefile template
include cs225/make/cs225.mk
