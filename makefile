#Compiler
CC=g++ -O2

all: bin/Problem001.exe bin/Problem002.exe bin/Problem003.exe bin/Problem004.exe bin/Problem005.exe bin/Problem006.exe bin/Problem007.exe bin/Problem008.exe bin/Problem009.exe bin/Problem010.exe bin/Problem011.exe bin/Problem012.exe bin/Problem014.exe bin/Problem021.exe bin/Problem023.exe bin/Problem031.exe bin/Problem033.exe bin/Problem045.exe bin/Problem050.exe bin/Problem301.exe

bin/Problem001.exe:
	${CC} -o bin/Problem001.exe Problem001.cpp

bin/Problem002.exe:
	${CC} -o bin/Problem002.exe Problem002.cpp

bin/Problem003.exe:
	${CC} -o bin/Problem003.exe Problem003.cpp

bin/Problem004.exe:
	${CC} -o bin/Problem004.exe Problem004.cpp

bin/Problem005.exe:
	${CC} -o bin/Problem005.exe Problem005.cpp

bin/Problem006.exe:
	${CC} -o bin/Problem006.exe Problem006.cpp

bin/Problem007.exe:
	${CC} -o bin/Problem007.exe Problem007.cpp

bin/Problem008.exe:
	${CC} -o bin/Problem008.exe Problem008.cpp

bin/Problem009.exe:
	${CC} -o bin/Problem009.exe Problem009.cpp

bin/Problem010.exe:
	${CC} -o bin/Problem010.exe Problem010.cpp

bin/Problem011.exe:
	${CC} -o bin/Problem011.exe Problem011.cpp

bin/Problem012.exe:
	${CC} -o bin/Problem012.exe Problem012.cpp

bin/Problem014.exe:
	${CC} -o bin/Problem014.exe Problem014.cpp

bin/Problem021.exe:
	${CC} -o bin/Problem021.exe Problem021.cpp

bin/Problem023.exe:
	${CC} -o bin/Problem023.exe Problem023.cpp

bin/Problem031.exe:
	${CC} -o bin/Problem031.exe Problem031.cpp

bin/Problem033.exe:
	${CC} -o bin/Problem033.exe Problem033.cpp

bin/Problem045.exe:
	${CC} -o bin/Problem045.exe Problem045.cpp

bin/Problem050.exe:
	${CC} -o bin/Problem050.exe Problem050.cpp

bin/Problem301.exe:
	${CC} -o bin/Problem301.exe Problem301.cpp
