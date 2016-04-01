CXX=g++
CXXFLAGS=-std=c++14 -Wall -ggdb -I ./include
LDFLAGS=-shared -L ./obj -lEulerShared
BIN=ProjectEuler
SRC := $(shell find ./EulerQuestions -name '*.cpp')
OBJ := $(addprefix obj/,$(notdir $(SRC:.cpp=.o)))

VPATH=$(dir $(SRC))

all: $(OBJ)
#	@echo $(OBJ)
#	@echo $(SRC)
	$(CXX) $(LDFLAGS) -o $(BIN) $^

$(OBJ): | obj
#	@echo $@

obj/%.o: %.cpp
#	@echo pie
	$(CXX) $(CXXFLAGS) -o $@ -c $< 


	
obj:
#	@echo cheese
	@mkdir -p $@


clean:
	rm -f $(BIN)
	rm -rf obj

