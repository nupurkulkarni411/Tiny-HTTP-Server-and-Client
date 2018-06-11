CXX=g++

LIBCFLAGS=-std=c++14 -I../Sockets -I../Message -g
EXECFLAGS=-std=c++14 -I../Sockets -I../Message -DTEST_HTTPCOMMCORE -g

LIBLDFLAGS=-L../Sockets -L../Message -lsocket -lMessage -fPIC -shared -lpthread
EXELDFLAGS=-L../Sockets -L../Message -lsocket -lMessage -lpthread

EXE=HttpCommCore
LIB=libHttpCommCore.so
SRC=HttpCommCore.cpp

lib:
	$(CXX) -o $(LIB) $(SRC) $(LIBCFLAGS) $(LIBLDFLAGS)

exe:
	$(CXX) -o $(EXE) $(SRC) $(EXECFLAGS) $(EXELDFLAGS)


clean:
	rm -rf $(EXE) $(LIB)
