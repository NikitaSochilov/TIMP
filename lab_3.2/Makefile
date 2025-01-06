# Определяем компилятор и его флаги
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Указываем файлы исходного кода и тестов
SRC_FILES = modPerm.cpp main.cpp
TEST_FILES = test_modPerm.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)
TEST_OBJ_FILES = $(TEST_FILES:.cpp=.o)

# Исполняемые файлы
TARGET = modPermCipher
TEST_TARGET = test_modPermCipher

# Основная цель
all: $(TARGET) $(TEST_TARGET)

# Правило для сборки исполняемого файла основной программы
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Правило для сборки исполняемого файла тестов
$(TEST_TARGET): modPerm.o test_modPerm.o
	$(CXX) $(CXXFLAGS) -o $@ $^ -lUnitTest++

# Правило для сборки объектных файлов
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Псевдонимы для команд
.PHONY: clean all run test

# Очистка скомпилированных файлов
clean:
	rm -rf *.o $(TARGET) $(TEST_TARGET)

# Запуск основной программы
run: $(TARGET)
	./$(TARGET)

# Запуск тестов
test: $(TEST_TARGET)
	./$(TEST_TARGET)