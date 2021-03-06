###############################################################################
# Makefile to compile and install this software.
###############################################################################
# Copyright (c) 2018 Gabriel Grechuk da Silva Oliveira
#
# Under the MIT License. Checkout the LICENSE.txt file.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
# DEALINGS IN THE SOFTWARE.
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



# Rules to build.
#################

# Local Compilation Linux.
local: build clean

# Building For Linux.
build: $(OBJ_FILES) $(EXEC)


# Local Compilation Windows.
local-windows: build-windows clean

# Building for Windows
build-windows: $(OBJ_FILES) $(WIN_EXEC)


# Clear object files.
clean:
	@echo "Cleaning residual files"
	@rm -r $(OBJ_PATH)
	@echo "Done!"

.PHONY: install-linux local local-windows



# Intalation on Linux
install-linux: local
	@sudo mv $(EXEC) $(INSTALL_PATH_LINUX)
	@echo "Aplication Installed!"

uninstall-linux:
	@sudo rm "$(INSTALL_PATH_LINUX)/$(EXEC)"
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
