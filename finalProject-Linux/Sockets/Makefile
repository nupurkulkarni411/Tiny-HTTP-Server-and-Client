CXX=g++

LIBCFLAGS=-std=c++14 -I../blockingQueue/ -I../Logger -I../Utilities
EXECFLAGS=-std=c++14 -I../blockingQueue/ -I../Logger -I../Utilities -DTEST_SOCKETS -g

LIBLDFLAGS=-L../blockingQueue/ -lblockingq -L../Logger -llogger -fPIC -shared -lpthread
EXELDFLAGS=-L../blockingQueue/ -lblockingq -L../Logger -llogger -L../Utilities -lutils -lpthread -g

EXE=sockets
LIB=libsocket.so
SRC=Sockets.cpp

lib:
	$(CXX) -o $(LIB) $(SRC) $(EXECFLAGS) $(LIBLDFLAGS)

exe:
	$(CXX) -o $(EXE) $(SRC) $(EXECFLAGS) $(EXELDFLAGS)

clean:
	rm -rf $(EXE) $(LIB) 
