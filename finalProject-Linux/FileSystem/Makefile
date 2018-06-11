CXX=g++

LIBCFLAGS=-std=c++14 -g 
EXECFLAGS=-std=c++14 -DTEST_FILESYSTEM -g

LIBLDFLAGS= -fPIC -shared -lpthread
EXELDFLAGS= -lpthread

EXE=FileSystem
LIB=libFileSystem.so
SRC=FileSystem.cpp

lib:
	$(CXX) -o $(LIB) $(SRC) $(LIBCFLAGS) $(LIBLDFLAGS)

exe:
	$(CXX) -o $(EXE) $(SRC) $(EXECFLAGS) $(EXELDFLAGS)

clean:
	rm -rf $(EXE) $(LIB)
