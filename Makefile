CXX = g++
CXXFLAGS = -std=c++17 -Wall `pkg-config --cflags gtk+-3.0`
LIBS = `pkg-config --libs gtk+-3.0` -pthread
TARGET = racheta_app

all: $(TARGET)
$(TARGET): main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o $(TARGET) $(LIBS)
clean:
	rm -f $(TARGET)
