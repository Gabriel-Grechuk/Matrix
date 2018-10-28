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
EXEC = matrix
# For windows
WIN_EXEC = matrix.exe

# Path to install the binary file
# LINUX
INSTALL_PATH_LINUX = /usr/local/bin

#Path to install the biinary file
# WINDOWS
INSTALL_PATH_WINDOWS = %ProgramFiles%\matrix



# Rules to build.
#################

local: build clean

build: $(OBJ_FILES) $(EXEC)

clean:
	@echo "Cleaning residual files"
	@rm -r $(OBJ_PATH)
	@echo "Done!"



# Intalation on Linux
install-linux: all
	@sudo mv $(EXEC) $(INSTALL_PATH_LINUX)
	@echo "Aplication Installed!"

uninstall-linux:
	@sudo rm "$(INSTALL_PATH_LINUX)/$(EXEC)"
	@echo "Aplication uninstalled."



# Instalation on Windows
install-windows: $(OBJ_FILES) $(WIN_EXEC) clean
	@mkdir -p $(INSTALL_PATH_WINDOWS)
	@mv matrix $(INSTALL_PATH_WINDOWS)
	#@set PATH=%PATH%;$(INSTALL_PATH_WINDOWS)
	@echo "Aplication Installed!"

uninstall-windows:
	@rm  $(INSTALL_PATH_WINDOWS)\$(WIN_EXEC)
	@echo "Aplication uninstalled."



# Builds.
#########

# main.o
main.o:  main.cpp
	@echo "Buildin main.o - 33%"
	@mkdir -p $(OBJ_PATH)
	@$(CC) -c $< -o $(OBJ_PATH)/$@

# matrix.o
matrix.o: matrix_class/matrix.cpp matrix_class/matrix.h
	@echo "Building matrix.o - 66%"
	@mkdir -p $(OBJ_PATH)
	@$(CC) -c $< -o $(OBJ_PATH)/$@


# matrix (binary file)
$(EXEC): $(OBJ_PATH)/main.o $(OBJ_PATH)/matrix.o
	@echo "Building $(EXEC) - 100%"
	@$(CC) $^ -o $(EXEC)


# matrix (binary file)
$(WIN_EXEC): $(OBJ_PATH)/main.o $(OBJ_PATH)/matrix.o
	@echo "Building $(WIN_EXEC) - 100%"
	@$(CC) $^ -o $(WIN_EXEC)