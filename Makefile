###############################################################################
# Makefile para construir os arquivos binários.
###############################################################################
# Created by Grechuk <gabrielgrechuk@outlook.com>
###############################################################################
# There is NO WARRANTY of any kind.
###############################################################################

# Variables
###########

# C++ compiler
CC = g++

# Path of the object files.
OBJ_PATH = obj

# Object files
OBJ_FILES = main.o matrix.o

# Binary file
EXEC = Matrix



# Rules to build.
#################

all: build clean

build: $(OBJ_FILES) $(EXEC)

clean:
	@rm -r $(OBJ_PATH)



# Builds.
#########

# main.o
main.o:  main.cpp
	@echo "Buildin main.o\n"
	@mkdir -p $(OBJ_PATH)
	$(CC) -c $< -o $(OBJ_PATH)/$@

# matrix.o
matrix.o: matrix/matrix.cpp matrix/matrix.h
	@echo "Building matrix.o\n"
	@mkdir -p $(OBJ_PATH)
	$(CC) -c $< -o $(OBJ_PATH)/$@


# matrix (binary file)
$(EXEC): $(OBJ_PATH)/main.o $(OBJ_PATH)/matrix.o
	@echo "Building $(EXEC)\n"
	$(CC) $^ -o $(EXEC)
