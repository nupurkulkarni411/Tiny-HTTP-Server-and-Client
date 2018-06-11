#!/bin/bash

cd Utilities && make lib && cd ../
cd FileSystem && make lib && cd ../
cd blockingQueue && make lib && cd ../
cd Logger && make lib && cd ../
cd Message && make lib && cd ../
cd Sockets && make lib && cd ../
cd HttpCommCore && make lib && cd ../
cd HttpClient && make && cd ../
cd HttpServer && make && cd ../
