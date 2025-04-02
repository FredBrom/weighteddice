CC = gcc
CFLAGS = -Wall -Wextra -g
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INCLUDE_DIR = include
TESTS_DIR = test


# Selec all src files
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)

# Generate a list of object files to target
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Select all tests files
TEST_FILES := $(wildcard $(TESTS_DIR)/*.c)
TEST_BINS := $(patsubst $(TESTS_DIR)/%.c,$(BIN_DIR)/%, $(TEST_FILES))

# Main Target
all: $(OBJ_FILES) $(TEST_BINS)

# Compile .c file to object code
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -I$(INCLUDE_DIR) $< -o $@

# Compile .c files in test to binaries
$(BIN_DIR)/%: $(TESTS_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(OBJ_FILES) $< -o $@

clean:
	rm -f $(OBJ_FILES)
	rm -f $(TEST_BINS)

# Create ./obj if it don't exist
$(OBJ_DIR)/%.o: | $(OBJ_DIR)
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Create .bin if it don't exist
$(BIN_DIR)/%: | $(BIN_DIR)
$(BIN_DIR):
	mkdir -p $(BIN_DIR)
