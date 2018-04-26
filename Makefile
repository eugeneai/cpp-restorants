.PHONY: comp run clean


CPPFLAGS=-std=c++11  -O0 -g3

TARGET=prog


SRC=prog.cpp

run: comp
	./$(TARGET)

comp: $(TARGET)

clean:
	rm -f *.o prog
