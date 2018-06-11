#!/bin/bash

export LD_LIBRARY_PATH=/home/nachiket/src/DO_Project/HTTP_Server/2-28/finalproject/blockingQueue:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH=/home/nachiket/src/DO_Project/HTTP_Server/2-28/finalproject/FileSystem:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH=/home/nachiket/src/DO_Project/HTTP_Server/2-28/finalproject/Message:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH=/home/nachiket/src/DO_Project/HTTP_Server/2-28/finalproject/Sockets:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH=/home/nachiket/src/DO_Project/HTTP_Server/2-28/finalproject/Utilities:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH=/home/nachiket/src/DO_Project/HTTP_Server/2-28/finalproject/HttpCommCore:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH=/home/nachiket/src/DO_Project/HTTP_Server/2-28/finalproject/Logger:$LD_LIBRARY_PATH

./httpClient
