CXX=g++

#LIBCFLAGS=-std=c++14 -I../blockingQueue/ -g
EXECFLAGS=-std=c++14 -I../blockingQueue/ -I../FileSystem -I../Logger -I../Sockets -I../Message -I../HttpCommCore -I../Utilities -g

#LIBLDFLAGS=-L../blockingQueue/ -lblockingq -fPIC -shared -lpthread
EXELDFLAGS=-L../blockingQueue/ -L../FileSystem -L../Logger -L../Sockets -L../Message -L../HttpCommCore -L../Utilities -lblockingq -lsocket -lHttpCommCore -lFileSystem -llogger -lMessage -lutils -lpthread

EXE=httpServer
#LIB=liblogger.so
SRC=HttpServer.cpp

#lib:
#	$(CXX) -o $(LIB) $(SRC) $(LIBCFLAGS) $(LIBLDFLAGS)

exe:
	$(CXX) -o $(EXE) $(SRC) $(EXECFLAGS) $(EXELDFLAGS)

clean:
	rm -rf $(EXE) $(LIB)
