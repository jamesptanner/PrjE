LIBVER=1.0.0
LIBNAME=libEulerRunner.so
LIBMAJ=1

CXX=g++
CXXFLAGS=-std=c++14 -Wall -ggdb -fPIC
LDFLAGS=--shared -W1,-soname,$(LIBNAME).$(LIBMAJ)
BIN=../out/$(LIBNAME).$(LIBVER)

SRC=$(wildcard *.cpp)
OBJ=$(patsubst %.cpp,../obj/%.o,$(SRC))

all: $(OBJ)
	$(CXX) $(LDFLAGS) -o $(BIN) $^

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
	rm -rf ../obj
	rm -rf ../out
	rm -rf ../include

install:
	
