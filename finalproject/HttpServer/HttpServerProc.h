#pragma once
/////////////////////////////////////////////////////////////////////////
// HttpServerProc.h - Provides application specific server processing  //
// ver 1.0                                                             //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2018           //
// Application: OOD Projects                                           //
// Platform:    Visual Studio 2017, Dell XPS 8920, Windows 10 pro      //
/////////////////////////////////////////////////////////////////////////
/*
*  Processor Operations:
* -----------------------
* This package implements application specific processing, e.g., 
* transformation of HttpMessage<HttpRequest> into HttpMessage<HttpReply>.
*
*  Required Files:
* -----------------
*   HttpServerProc.h
*   Message.h, Message.cpp
*   Utilities.h, Utilities.cpp
*
*  Maintenance History:
* ----------------------
*   ver 1.0 : 07 Jan 2017
*   - first release
*
*/

#include "../Message/Message.h"
#include "../Utilities/Utilities.h"
#include "../FileSystemDemo/FileSystem.h"
#include <fstream>
#include <string>
#include <vector>
#undef DELETE

namespace HttpCommunication
{
  //----< helper function for ClientHandler operator() >---------------
  /*
  *  - This function is provided by each application to define
  *    its server processing.
  */
  inline HttpMessage<HttpReply> makeReplyMessage(HttpMessage<HttpRequest> msg)
  {
	  if (msg.type().command() == HttpRequest::GET) {
		  if (msg.action() == "Connection check") {
			  size_t status = 200;
			  HttpMessage<HttpReply> reply = makeHttpReplyMessage(status);
			  std::string replyStr = "<!DOCTYPE html><html><head><style>";
			  replyStr += "body{ margin:5% ; font-family: Tahoma, Consolas, Sansserif; font-size:14; }";
			  replyStr += "</style></head><body>";
			  replyStr += "<h3>Received server message: Connection OK</h3>";
			  replyStr += "</body></html>";
			  reply.body() = replyStr;
			  reply.contentLength(reply.body().size());
			  return reply;
		  }
		  if (msg.action() == "View" && msg.attributes().at("version") == "latest") {
			  size_t status = 200;
			  HttpMessage<HttpReply> reply = makeHttpReplyMessage(status);
			  std::string pattern = msg.type().fileSpec().substr(0, msg.type().fileSpec().find_last_of(".")) + "*." + msg.type().fileSpec().substr(msg.type().fileSpec().find_last_of(".") + 1);
			  std::vector<std::string> getFiles = FileSystem::Directory::getFiles(FileSystem::Path::getFullFileSpec("../ServerStorage"), pattern);
			  std::string replyStr, file;
			  int maxCount = 0, count = 0, filenumber = 0;
			  if (getFiles.size() == 1) {
				  file = "../ServerStorage/" + getFiles[0];
			  }
			  else {
				  for (int i = 0; i < getFiles.size(); i++) {
					  if (getFiles[i].find_first_of("0123456789") != std::string::npos) {
						  count = std::stoi(getFiles[i].substr(getFiles[i].find_first_of("0123456789"), getFiles[i].find_last_of(".")));
					  }
					  if (count > maxCount) {
						  maxCount = count;
						  filenumber = i;
					  }
				  }
				  file = "../ServerStorage/" + getFiles[filenumber];
			  }
			  std::string fileName = FileSystem::Path::getFullFileSpec(file);
			  std::ifstream inFile;
			  inFile.open(fileName);
			  if (!inFile) {
				  std::cout << "\nUnable to open a file";
			  }
			  else {
				  std::ifstream in(fileName);
				  std::stringstream b;
				  b << in.rdbuf();
				  std::string b1 = b.str();
				  replyStr = b1;
			  }
			  reply.attribute("filename", msg.type().fileSpec());
			  reply.body() = replyStr;
			  reply.contentLength(reply.body().size());
			  return reply;
		  }
		  if (msg.action() == "View" && msg.attributes().at("version") == "selected") {
			  size_t status = 200;
			  HttpMessage<HttpReply> reply = makeHttpReplyMessage(status);
			  std::vector<std::string> getFiles = FileSystem::Directory::getFiles(FileSystem::Path::getFullFileSpec("../ServerStorage"), msg.type().fileSpec());
			  std::string replyStr;
			  std::string fileName = FileSystem::Path::getFullFileSpec("../ServerStorage/" + getFiles[0]);
			  std::ifstream inFile;
			  inFile.open(fileName);
			  if (!inFile) {
				  std::cout << "\nUnable to open a file";
			  }
			  else {
				  std::ifstream in(fileName);
				  std::stringstream b;
				  b << in.rdbuf();
				  std::string b1 = b.str();
				  replyStr = b1;
			  }
			  reply.attribute("filename", msg.type().fileSpec());
			  reply.body() = replyStr;
			  reply.contentLength(reply.body().size());
			  return reply;
		  }
		  if (msg.action() == "GetRepoContent") {
			  size_t status = 200;
			  HttpMessage<HttpReply> reply = makeHttpReplyMessage(status);
			  std::string replyStr;
			  std::vector<std::string> content = FileSystem::Directory::getFiles("../ServerStorage");
			  for (auto f : content) {
				  replyStr += f + "\n";
			  }
			  reply.body() = replyStr;
			  reply.contentLength(reply.body().size());
			  return reply;
		  }
		  if (msg.action() == "File CheckOut" ) {
			  if (msg.attributes().at("version") == "latest") {
				  size_t status = 200;
				  HttpMessage<HttpReply> reply = makeHttpReplyMessage(status);
				  std::string pattern = msg.type().fileSpec().substr(0, msg.type().fileSpec().find_last_of(".")) + "*." + msg.type().fileSpec().substr(msg.type().fileSpec().find_last_of(".") + 1);
				  std::vector<std::string> getFiles = FileSystem::Directory::getFiles(FileSystem::Path::getFullFileSpec("../ServerStorage"), pattern);
				  std::string replyStr, file;
				  int maxCount = 0, count = 0, filenumber = 0;
				  if (getFiles.size() == 1) {
					  file = "../ServerStorage/" + getFiles[0];
				  }
				  else {
					  for (int i = 0; i < getFiles.size(); i++) {
						  if (getFiles[i].find_first_of("0123456789") != std::string::npos) {
							  count = std::stoi(getFiles[i].substr(getFiles[i].find_first_of("0123456789"), getFiles[i].find_last_of(".")));
						  }
						  if (count > maxCount) {
							  maxCount = count;
							  filenumber = i;
						  }
					  }
					  file = "../ServerStorage/" + getFiles[filenumber];
				  }
				  std::string fileName = FileSystem::Path::getFullFileSpec(file);
				  std::ifstream inFile;
				  inFile.open(fileName);
				  if (!inFile) {
					  std::cout << "\nUnable to open a file";
				  }
				  else {
					  std::ifstream in(fileName);
					  std::stringstream b;
					  b << in.rdbuf();
					  std::string b1 = b.str();
					  replyStr = b1;
				  }
				  reply.attribute("filename", msg.type().fileSpec());
				  reply.body() = replyStr;
				  reply.contentLength(reply.body().size());
				  return reply;
			  }
			  else if (msg.attributes().at("version") == "selected") {
				  size_t status = 200;
				  HttpMessage<HttpReply> reply = makeHttpReplyMessage(status);
				  std::vector<std::string> getFiles = FileSystem::Directory::getFiles(FileSystem::Path::getFullFileSpec("../ServerStorage"), msg.type().fileSpec());
				  std::ifstream in(FileSystem::Path::getFullFileSpec("../ServerStorage/" + getFiles[0]));
				  std::stringstream b;
				  b << in.rdbuf();
				  std::string b1 = b.str();
				  std::string replyStr = b1;
				  reply.attribute("filename", getFiles[0]);
				  reply.body() = replyStr;
				  reply.contentLength(reply.body().size());
				  return reply;
			  }
			  else {
				  size_t status = 200;
				  HttpMessage<HttpReply> reply = makeHttpReplyMessage(status);
				  std::string pattern,replyStr;
				  if(msg.attributes().at("version") == "0")
					  pattern = msg.type().fileSpec().substr(0, msg.type().fileSpec().find_last_of(".")) + "." + msg.type().fileSpec().substr(msg.type().fileSpec().find_last_of(".") + 1);
				  else
					  pattern = msg.type().fileSpec().substr(0, msg.type().fileSpec().find_last_of(".")) + msg.attributes().at("version")+"." + msg.type().fileSpec().substr(msg.type().fileSpec().find_last_of(".") + 1);
				  std::vector<std::string> getFiles = FileSystem::Directory::getFiles(FileSystem::Path::getFullFileSpec("../ServerStorage"), pattern);
				  std::ifstream in(FileSystem::Path::getFullFileSpec("../ServerStorage/"+getFiles[0]));
				  std::stringstream b;
				  b << in.rdbuf();
				  std::string b1 = b.str();
				  replyStr = b1;
				  reply.attribute("filename", getFiles[0]);
				  reply.body() = replyStr;
				  reply.contentLength(reply.body().size());
				  return reply;
			  }
			  
		  }
		  else {
			  size_t status = 400;
			  HttpMessage<HttpReply> reply = makeHttpReplyMessage(status);
			  return reply;
		  }
	  }
	  else if (msg.type().command() == HttpRequest::PUT) {
		  size_t count = 0;
		  std::string fileName = "../ServerStorage/" + msg.type().fileSpec();
		  size_t status = 200;
		  HttpMessage<HttpReply> reply = makeHttpReplyMessage(status);
		  std::string replyStr;
		  if (msg.action() == "File CheckIn" && msg.attributes().at("version") == "New") {
			  if (!FileSystem::File::exists(fileName)) {
				  std::ofstream outfile(fileName);
				  count = 0;
				  replyStr += "Ready to receive file : " + fileName;
			  }
			  else {
				  std::string pattern = msg.type().fileSpec().substr(0, msg.type().fileSpec().find_last_of(".")) + "*." + msg.type().fileSpec().substr(msg.type().fileSpec().find_last_of(".") + 1);
				  std::vector<std::string> getFiles = FileSystem::Directory::getFiles(FileSystem::Path::getFullFileSpec("../ServerStorage"), pattern);
				  count += getFiles.size();
				  std::string file = msg.type().fileSpec().substr(0,msg.type().fileSpec().find_last_of(".")) 
					  + std::to_string(count)
					  + msg.type().fileSpec().substr(msg.type().fileSpec().find_last_of("."));
				  fileName = "../ServerStorage/" + file;
				  std::ofstream outfile(fileName);
				  replyStr += "New version of file ready to receive : " + fileName;
			  }
		  }
		  else if (msg.action() == "File CheckIn" && msg.attributes().at("version") == "In-progress") {
			  std::ifstream in(FileSystem::Path::getFullFileSpec(msg.type().fileSpec()));
			  std::stringstream b;
			  b << in.rdbuf();
			  std::string b1 = b.str() + msg.body().toString();
			  std::ofstream outfile;
			  outfile.open(FileSystem::Path::getFullFileSpec(msg.type().fileSpec()));
			  outfile << b1;
			  outfile.close();
		  }
		  reply.body() = replyStr;
		  reply.contentLength(replyStr.size());
		  return reply;
	  }
	  else if (msg.type().command() == HttpRequest::DELETE) {
		  if (msg.attributes().at("version") == "all") {
			  size_t status = 200;
			  HttpMessage<HttpReply> reply = makeHttpReplyMessage(status);
			  std::string pattern = msg.type().fileSpec().substr(0, msg.type().fileSpec().find_last_of(".")) + "*." + msg.type().fileSpec().substr(msg.type().fileSpec().find_last_of(".") + 1);
			  std::vector<std::string> getFiles = FileSystem::Directory::getFiles(FileSystem::Path::getFullFileSpec("../ServerStorage"), pattern);
			  std::string replyStr;
			  if (getFiles.empty()) {
				  replyStr = "File doesn't exist";
				  reply.body() = replyStr;
				  reply.contentLength(reply.body().size());
				  return reply;
			  }
			  for (auto f : getFiles) {
				  std::string fullName = FileSystem::Path::getFullFileSpec("../ServerStorage/" + f);
				  FileSystem::File::remove(fullName);
			  }
			  std::vector<std::string> content = FileSystem::Directory::getFiles(FileSystem::Path::getFullFileSpec("../ServerStorage"));

			  for (auto f : content) {
				  replyStr += f + "\n";
			  }
			  reply.body() = replyStr;
			  reply.contentLength(reply.body().size());
			  return reply;
		  }
		  if (msg.attributes().at("version") == "selected") {
			  size_t status = 200;
			  HttpMessage<HttpReply> reply = makeHttpReplyMessage(status);
			  std::vector<std::string> getFiles = FileSystem::Directory::getFiles(FileSystem::Path::getFullFileSpec("../ServerStorage"), msg.type().fileSpec());
			  std::string replyStr;
			  if (getFiles.empty()) {
				  replyStr = "File doesn't exist";
				  reply.body() = replyStr;
				  reply.contentLength(reply.body().size());
				  return reply;
			  }
			  for (auto f : getFiles) {
				  std::string fullName = FileSystem::Path::getFullFileSpec("../ServerStorage/" + f);
				  FileSystem::File::remove(fullName);
			  }
			  std::vector<std::string> content = FileSystem::Directory::getFiles(FileSystem::Path::getFullFileSpec("../ServerStorage"));

			  for (auto f : content) {
				  replyStr += f + "\n";
			  }
			  reply.body() = replyStr;
			  reply.contentLength(reply.body().size());
			  return reply;
		  }
		  else {
			  size_t status = 400;
			  HttpMessage<HttpReply> reply = makeHttpReplyMessage(status);
			  return reply;
		  }
	  }
	  else {
		  size_t status = 404;
		  HttpMessage<HttpReply> reply = makeHttpReplyMessage(status);
		  std::string replyStr = "Bad Request";
		  reply.body() = replyStr;
		  reply.contentLength(replyStr.size());
		  return reply;
	  }
  }
}