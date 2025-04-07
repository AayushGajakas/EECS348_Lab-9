# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Target executable
TARGET = matrix_program

# Source files
SRCS = main.cpp

# Output binary
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Clean up compiled files
clean:
	rm -f $(TARGET)
