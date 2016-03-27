CXX=g++
CXXFLAGS=-std=c++14 -Wall -ggdb
LDFLAGS=
BIN=ProjectEuler

SRC=$(wildcard *.cpp)
OBJ=$(patsubst %.cpp,obj/%.o,$(SRC))

all: $(OBJ)
	$(CXX) $(LDFLAGS) -o $(BIN) $^

$(OBJ): | obj

obj:
	@mkdir -p $@

obj/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $< 

clean:
	rm -f $(BIN)
	rm -rf obj

