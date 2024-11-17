# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# File names
SOURCES = queue.cpp test.cpp
HEADERS = queue.h
BUILD_DIR = build
EXECUTABLE = $(BUILD_DIR)/test

# Create build directory if it doesn't exist
$(shell mkdir -p $(BUILD_DIR))

# Object files will be placed in the build directory
OBJECTS = $(SOURCES:%.cpp=$(BUILD_DIR)/%.o)

# Default target
all: $(EXECUTABLE)

# Link object files to create the executable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXECUTABLE)

# Compile .cpp files into .o files in the build directory
$(BUILD_DIR)/%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the tests after building
run: $(EXECUTABLE)
	./$(EXECUTABLE)

# Clean up build files
clean:
	rm -rf $(BUILD_DIR)
