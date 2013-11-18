# Compiler
CXX=g++ -O2

# Make a list of all the .cpp files
CPP_FILES := $(wildcard src/*.cpp)
# substitute .cpp for .exe from the $(CPP_FILES) list
TMP := $(subst .cpp,.exe,$(CPP_FILES))
# Substitute bin for src for each file in $(TMP)
EXE_FILES := $(subst src/,,$(TMP))

# Make all the files in $(EXE_FILES)
all: $(EXE_FILES)

# Every .exe file is derived from the .cpp with the same name
%.exe: src/%.cpp
	$(CXX) -o $@ $^

# Clean up
clean:
	rm -rf $(EXE_FILES)
