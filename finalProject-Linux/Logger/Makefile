CXX=g++

LIBCFLAGS=-std=c++14 -I../blockingQueue/ -g
EXECFLAGS=-std=c++14 -I../blockingQueue/ -DTEST_LOGGER -g

LIBLDFLAGS=-L../blockingQueue/ -lblockingq -fPIC -shared -lpthread
EXELDFLAGS=-L../blockingQueue/ -lblockingq -lpthread

EXE=logger
LIB=liblogger.so
SRC=Logger.cpp

lib:
	$(CXX) -o $(LIB) $(SRC) $(LIBCFLAGS) $(LIBLDFLAGS)

exe:
	$(CXX) -o $(EXE) $(SRC) $(EXECFLAGS) $(EXELDFLAGS)

clean:
	rm -rf $(EXE) $(LIB)
