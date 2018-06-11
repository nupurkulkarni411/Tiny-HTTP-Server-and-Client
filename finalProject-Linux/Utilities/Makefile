CXX=g++

LIBCFLAGS=-std=c++14 -g
EXECFLAGS=-std=c++14 -DTEST_UTILITIES -g

LIBLDFLAGS= -fPIC -shared -lpthread
EXELDFLAGS= -lpthread

EXE=utils
LIB=libutils.so
SRC=Utilities.cpp

lib:
	$(CXX) -o $(LIB) $(SRC) $(LIBCFLAGS) $(LIBLDFLAGS)

exe:
	$(CXX) -o $(EXE) $(SRC) $(EXECFLAGS) $(EXELDFLAGS)

clean:
	rm -rf $(EXE) $(LIB)
