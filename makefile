# Compiler
CXXFLAGS=-O3 -pipe -Wall -pedantic -Wconversion -Wextra -std=c++11
RM=rm -f

# Make a list of all the files we need
# We use substitution to make the other lists from the cpp list
CPP_FILES := $(wildcard src/Pro*.cpp)  # Make a list of all cpp files
TMP := $(subst .cpp,.exe,$(CPP_FILES)) # Replace '.cpp' with '.exe'
EXE_FILES := $(subst src/,,$(TMP))     # Replace 'src/' with ''
OBJ_FILES := obj/alexlib.o

# Make all the files in $(EXE_FILES)
all: $(EXE_FILES)

# Every .exe file is derived from the .cpp with the same name
%.exe: src/%.cpp $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Build our library
obj/alexlib.o: src/lib/alexlib.h src/lib/alexlib.cpp src/lib/alexlib.tcc
	$(CXX) $(CXXFLAGS) -c src/lib/alexlib.cpp -o $@

# Clean up
clean-all:
	$(RM) $(EXE_FILES) $(OBJ_FILES)

clean:
	$(RM) $(OBJ_FILES)
