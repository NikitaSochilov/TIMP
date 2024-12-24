
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g -I/usr/include/UnitTest++


TARGET = transposition_cipher
TEST_TARGET = test_transposition_cipher


SRCS = transposition_cipher.cpp main.cpp
TEST_SRCS = test_transposition_cipher.cpp transposition_cipher.cpp

.PHONY: all clean test


all: $(TARGET)


$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)


test: $(TEST_TARGET)
	./$(TEST_TARGET) || true


$(TEST_TARGET): $(TEST_SRCS)
	$(CXX) $(CXXFLAGS) $(TEST_SRCS) -o $(TEST_TARGET) -lUnitTest++


clean:
	rm -f $(TARGET) $(TEST_TARGET)
