.PHONY: comp run


CPPFLAGS=-O0 -g3

TARGET=prog
SRC=prog.cpp

run: comp
	./$(TARGET)

comp: prog

$(TERGET): $(SRC)
	g++ $< -o $@ $(CPPFLAGS)
