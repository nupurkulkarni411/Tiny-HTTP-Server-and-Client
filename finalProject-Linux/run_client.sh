#!/bin/bash

DIR=`pwd`

export LD_LIBRARY_PATH=$DIR/blockingQueue:$DIR/FileSystem:$DIR/HttpCommCore:$DIR/Message:$DIR/Logger:$DIR/Sockets:$DIR/Utilities:$LD_LIBRARY_PATH

cd HttpClient
./httpClient
