IDIR = ./include
CC = gcc
CFLAGS = -I$(IDIR)

#OBJS specifies which files to compile as part of the project
OBJS = ./main.c

#linker flags
LINKER_FLAGS = -lm

#name of the executable
OBJ_NAME = matrices

#compile
all : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
