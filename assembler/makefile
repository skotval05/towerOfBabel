CC = gcc

BUILD_DIR = build
SRC = assembler.c

CFLAGS = -I"C:/msys64/mingw64/include"

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

assembler: $(BUILD_DIR) $(SRC)
	$(CC) -o $(BUILD_DIR)/assembler $(SRC) $(CFLAGS)
