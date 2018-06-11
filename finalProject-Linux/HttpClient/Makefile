CXX=g++

#LIBCFLAGS=-std=c++14 -I../blockingQueue/ -g
EXECFLAGS=-std=c++14 -I../blockingQueue/ -I../Sockets -I../Message -I../HttpCommCore -I../Utilities -I../Logger -g

#LIBLDFLAGS=-L../blockingQueue/ -lblockingq -fPIC -shared -lpthread
EXELDFLAGS=-L../blockingQueue/ -L../Sockets -L../Message -L../HttpCommCore -L../Utilities -L../Logger -lblockingq -lsocket -lHttpCommCore -lMessage -lutils -llogger -lpthread

EXE=httpClient
#LIB=liblogger.so
SRC=HttpClient.cpp

#lib:
#	$(CXX) -o $(LIB) $(SRC) $(LIBCFLAGS) $(LIBLDFLAGS)

exe:
	$(CXX) -o $(EXE) $(SRC) $(EXECFLAGS) $(EXELDFLAGS)

clean:
	rm -rf $(EXE) $(LIB)
