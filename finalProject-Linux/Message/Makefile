CXX=g++

LIBCFLAGS=-std=c++14 -g 
EXECFLAGS=-std=c++14 -DTEST_BLOCKINGQUEUE -g

LIBLDFLAGS= -fPIC -shared -lpthread
EXELDFLAGS= -lpthread

EXE=Message
LIB=libMessage.so
SRC=Message.cpp

lib:
	$(CXX) -o $(LIB) $(SRC) $(LIBCFLAGS) $(LIBLDFLAGS)

exe:
	$(CXX) -o $(EXE) $(SRC) $(EXECFLAGS) $(EXELDFLAGS)

clean:
	rm -rf $(EXE) $(LIB)
