#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <cstdio>
//#include <regex>  // not complete for g++
#include <stdlib.h>
#include <time.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <sys/stat.h>
#include <sys/sendfile.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include "FileSystem.h"

using namespace FileSystem;

int main() {
	/*std::string str = "/home/nachiket/src/DO_Project/5-3/newCode/ServerStorage/Graph5.cpp";
//	class Path path;
//	std::cout << "----------- " << path.getFullFileSpec(str) << std::endl;
	File file(str);
	file.remove(str);*/

	std::string pattern = "Graph*.cpp";
	std::vector<std::string> getFiles = FileSystem::Directory::getFiles(FileSystem::Path::getFullFileSpec("../ServerStorage"), pattern);
	for (auto i : getFiles)
		std::cout << "getFiles = " << i << std::endl;
	std::cout << "*** getFiles.size(); = " << getFiles.size();
}
