CXX = g++
CXXFLAGS = -std=c++11 -Wall -g -I/usr/include/UnitTest++
TARGET = modAlphaCipher
TEST_TARGET = test

# Исходные файлы
SRCS = modAlphaCipher.cpp main.cpp
TEST_SRCS = test.cpp modAlphaCipher.cpp

.PHONY: all clean test

# Цель по умолчанию
all: $(TARGET)

# Компиляция основной программы
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Запуск тестов
test: $(TEST_TARGET)

# Компиляция тестов
$(TEST_TARGET): $(TEST_SRCS)
	$(CXX) $(CXXFLAGS) $(TEST_SRCS) -o $(TEST_TARGET) -lUnitTest++

# Очистка временных файлов
clean:
	rm -f $(TARGET) $(TEST_TARGET)
