TARGET=rust_engine

CC=g++
CFLAGS=-lglfw -lGL -lGLEW

SRC_FOLDER=src/
BUILD_FOLDER=build/

SRC=$(wildcard $(SRC_FOLDER)*.cpp)
OBJ=$(patsubst $(SRC_FOLDER)%.cpp, $(BUILD_FOLDER)%.o, $(SRC))

.PHONY: install upload

$(TARGET): $(OBJ)
	@echo "---> Finishing building project..."
	@echo "---> Building $(OBJ) int $(TARGET)"
	@$(CC) $(OBJ) -o $(TARGET) $(CFLAGS)
	@echo "---> Finished building project!"
	@echo "---> Running compiled project..."
	@./$(TARGET)
	

$(BUILD_FOLDER)%.o: $(SRC_FOLDER)%.cpp
	@echo "---> Building $< into $@"
	@$(CC) -c $< -o $@ $(CFLAGS)

clean:
	@rm -rf $(TARGET) $(BUILD_FOLDER)*						