CXX=g++
CXXFLAGS=-std=c++14 -Wall -ggdb
LDFLAGS=--shared
BIN=../out/libSharedFunctions.so

SRC=$(wildcard *.cpp)
OBJ=$(patsubst %.cpp,../obj/%.o,$(SRC))

all: $(OBJ)
	$(CXX) $(LDFLAGS) -o $(BIN) $^
	cp EulerShared.h ../include/

$(OBJ): | ../obj ../out ../include

../obj:
	@mkdir -p $@

../out:
	@mkdir -p $@

../include: 
	@mkdir -p $@

../obj/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $< 

clean:
	rm -f $(BIN)
	rm -rf ../obj
	rm -rf ../out
	rm -rf ../include
