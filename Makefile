TARGET 		:= pokemon

SRC_DIR		:= src
INC_DIR		:= inc
OBJ_DIR		:= obj
BIN_DIR		:= bin

MAIN		:= main.cpp
SRCS		:= $(wildcard $(SRC_DIR)/*.cpp)
OBJS		:= $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
OBJS		+= $(OBJ_DIR)/main.o

CXX			:= g++
CXXFLAGS	:= -std=c++17 -Wall -Wextra -I$(INC_DIR)

EXEC		:= $(BIN_DIR)/$(TARGET)

.PHONY: all clean run help

all: $(EXEC)

$(OBJ_DIR):
	@mkdir -p $@

$(BIN_DIR):
	@mkdir -p $@

$(EXEC): $(OBJS) | $(BIN_DIR)
	$(CXX) $(OBJS) -o $@
	@echo "ejecutable creado."

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/main.o: $(MAIN) $(HEADERS) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS)  -c $< -o $@

run: all
	@./$(EXEC)

clean:
	@rm -rf $(BIN_DIR) $(OBJ_DIR)
	@echo "limpieza completa."

help:
	@echo "Comandos disponibles:"
	@echo "  make          → compila el proyecto"
	@echo "  make run      → compila y ejecuta"
	@echo "  make clean    → elimina obj/ y bin/"
	@echo "  make help     → muestra esta ayuda"