CXX=g++

LIBCFLAGS=-std=c++14 -g 
EXECFLAGS=-std=c++14 -DTEST_BLOCKINGQUEUE -g

LIBLDFLAGS= -fPIC -shared -lpthread
EXELDFLAGS= -lpthread

EXE=blockingq
LIB=libblockingq.so
SRC=Cpp11-BlockingQueue.cpp

lib:
	$(CXX) -o $(LIB) $(SRC) $(LIBCFLAGS) $(LIBLDFLAGS)

exe:
	$(CXX) -o $(EXE) $(SRC) $(EXECFLAGS) $(EXELDFLAGS)

clean:
	rm -rf $(EXE) $(LIB)
