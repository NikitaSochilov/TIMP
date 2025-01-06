# Определяем компилятор и его флаги
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Указываем файлы исходного кода и тестов
SRC_FILES = modGronsfeld.cpp
TEST_FILES = est_modGronsfeld.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)
TEST_OBJ_FILES = $(TEST_FILES:.cpp=.o)

# Исполняемые файлы
TARGET = encryptor
TEST_TARGET = test_encryptor

# Делаем все
all: $(TARGET) $(TEST_TARGET)

# Правило для сборки целевого исполняемого файла
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Правило для сборки исполняемого файла тестов
$(TEST_TARGET): $(OBJ_FILES) $(TEST_OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^ -lUnitTest++

# Правило для сборки объектных файлов
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Псевдонимы для команд
.PHONY: clean run test

# Правило для очистки проектных файлов
clean:
	rm -rf *.o $(TARGET) $(TEST_TARGET)

# Правило для запуска основного исполняемого файла
run: $(TARGET)
	./$(TARGET)

# Правило для запуска тестов
test: $(TEST_TARGET)
	./$(TEST_TARGET)