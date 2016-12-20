CXX=g++
CXXFLAGS=-std=c++14 -Wall -ggdb -I ../include -fPIC
LDFLAGS= -L../out/ -lEulerRunner -lSharedFunctions
BIN=../out/EulerQuestions
SRC := $(shell find . -name '*.cpp')
OBJ := $(addprefix ../obj/,$(notdir $(SRC:.cpp=.o)))

VPATH=$(dir $(SRC))

all: $(OBJ) | ../out
	$(CXX) -o $(BIN) $^ $(LDFLAGS)
	cp -r res ../out/
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
