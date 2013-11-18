# Compiler
CXX=g++
CXXFLAGS=-O2
RM=rm -f

# Make a list of all the files we need
# We use subsitution to make the other lists from the cpp list
CPP_FILES := $(wildcard src/Pro*.cpp)
TMP := $(subst .cpp,.exe,$(CPP_FILES))
EXE_FILES := $(subst src/,,$(TMP))
OBJ_FILES := obj/alexlib.o

# Make all the files in $(EXE_FILES)
all: $(EXE_FILES)

# Every .exe file is derived from the .cpp with the same name
%.exe: src/%.cpp obj/alexlib.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Build our library
obj/alexlib.o: src/alexlib.h src/alexlib.cpp
	$(CXX) $(CXXFLAGS) -c src/alexlib.cpp -o $@

# Clean up
clean-all:
	$(RM) $(EXE_FILES) $(OBJ_FILES)

clean:
	$(RM) $(OBJ_FILES)
