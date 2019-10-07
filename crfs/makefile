# SPECS

# Remove files not wanted
RM = rm -rfv
# Path to gcc compiler
CC = /usr/bin/gcc
# Compiler Flags
CFLAGS =
# Linker Flags
LDFLAGS = -lm


# PATHS

# Source path to find code files
SRC = src
# Path to .o files
OBJ = obj
# Headers path to header files
HDR = src/libsArchLinux
# Bulid path to create binaries in
BLD = .


# RESOURCES

# .c files
CFS = $(shell find $(SRC) -name '*.c')
# .o files
OFS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(CFS))
# bin files
BIN = crfs


# RULES

# Final Result
all: $(BIN)
# Result from .o files
$(BIN): $(OBJ)/$(OFS)
	$(CC) $(CFLAGS) -I$(HDR) -I$(SRC) $(OFS) -o $(BIN) $(LDFLAGS)
# .o files from .c files
$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) $(LDFLAGS) -I$(HDR) -I$(SRC) -c $< -o $@
# remove binaries and .o files
clean:
	$(RM) $(BIN) $(OFS)


# PS: This makefile works only when $(SRC) and $(OBJ) has the same tree structure.

