CXX=g++
CXXFLAGS=-std=c++14 -Wall -ggdb -I ../include
LDFLAGS=-shared -L../out/ -lSharedFunctions
BIN=../out/libEulerQuestions.so
SRC := $(shell find . -name '*.cpp')
OBJ := $(addprefix ../obj/,$(notdir $(SRC:.cpp=.o)))

VPATH=$(dir $(SRC))

all: $(OBJ) | ../out
	$(CXX) $(LDFLAGS) -o $(BIN) $^

$(OBJ): | ../obj

../obj/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $< 

../obj:
	@mkdir -p $@

../out:
	@mkdir -p $@

clean:
	rm -f $(BIN)
	rm -rf ../obj
	rm -rf ../out

