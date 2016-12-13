OBJS = test.c

OBJ_NAME = output

CC = clang

LINKER_FLAGS = -lSDL2 
COMPILER_FLAGS = -Weverything

all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
run: all
	./output
