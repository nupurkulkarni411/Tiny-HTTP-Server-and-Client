/////////////////////////////////////////////////////////////////////////
// HttpClient.cpp - Demonstrates simple HTTP messaging                 //
// ver 1.0                                                             //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2017           //
// Application: OOD Projects                                           //
// Platform:    Visual Studio 2017, Dell XPS 8920, Windows 10 pro      //
/////////////////////////////////////////////////////////////////////////

#include "../Sockets/Sockets.h"
#include "../Logger/Logger.h"
#include "../Utilities/Utilities.h"
#include "../Message/Message.h"
#include "../HttpCommCore/HttpCommCore.h"
#include "HttpClient.h"
#include <string>
#include <iostream>
#include <thread>
#include <fstream>

using Show = StaticLogger<1>;
using namespace Utilities;
using namespace Sockets;

using namespace HttpCommunication;

HttpClient::HttpClient() : HttpCommCore(&socket) {}

//----< sends message and waits for reply >----------------------------

HttpMessage<HttpReply> HttpClient::postMessage(HttpMessage<HttpRequest> msg)
{
  HttpCommCore::postMessage<HttpRequest>(msg);
  HttpMessage<HttpReply> reply = HttpCommCore::getMessage<HttpReply>();
  return reply;
}
//----< reconnect to new target >--------------------------------------

bool HttpClient::connect(const std::string& address, size_t port)
{
  socket.shutDown();
  return socket.connect(address, port);
}

int main()
{
  //SetConsoleTitle(L"HttpClient");
	std::cout << "HttpClient" << std::endl;
 
  Utilities::StringHelper::Title("HttpClient starting");
  std::cout << "\n Testing message processing for: ";
  std::cout << "\n ---------------------------- \n  1.Connect to server \n  2.CheckIn \n  3.CheckOut \n  4.Browse \n  5.View File  \n  7.Delete file";

  std::cout << "\n  press Enter to start: ";
  std::cout.flush();
  std::cin.get();
 
  //1. Connect to server
  std::cout << "\nOption 1";
  HttpMessage<HttpRequest> msg;
  msg.type().command(HttpRequest::GET);
  msg.action("Connection check");

	msg.type().fileSpec("../ServerStorage/Graph.cpp");

  HttpClient client;
  client.connect("localhost", 8080);
  std::cout << "\n--Posting message to localhost:8080:";
  msg.show();
  Utilities::putline();
  
  HttpMessage<HttpReply> reply = client.postMessage(msg);
  std::cout << "\n--Received reply:";
  reply.show();
  Utilities::putline();



  //2. CheckIn file
  std::cout << "\nOption 2";

  HttpMessage<HttpRequest> msg1;
  msg1.type().command(HttpRequest::PUT);
  msg1.action("File CheckIn");
  msg1.type().fileSpec("Graph.h");
  msg1.attribute("version","New");

  client.connect("localhost", 8080);
  std::cout << "\n--Posting message to localhost:8080:";
  msg1.show();
  Utilities::putline();

  HttpMessage<HttpReply> reply1 = client.postMessage(msg1);
  std::cout << "\n--Received reply:";
  reply1.show();
  Utilities::putline();


  std::ifstream inFile;
  inFile.open(client.clientPath + "Graph.h");
  if (!inFile) {
	  std::cout << "\nUnable to open a file";
  }
  else {
	  std::ifstream in(client.clientPath + "Graph.h");
	  std::stringstream b;
	  b << in.rdbuf();
	  std::string b1 = b.str();
	  std::cout << b1.size();
	 
	  if (b1.size() > 1024) {
		  size_t file_size = b1.size();
		  int i = 0;
		  while (file_size > 0) {
			  HttpMessage<HttpRequest> msg11;
			  msg11.type().command(HttpRequest::PUT);
			  msg11.action("File CheckIn");
			  msg11.type().fileSpec(reply1.body().toString().substr(reply1.body().toString().find_last_of(":") + 2));
			  if (file_size > 1024) {
				  msg11.body() = b1.substr(i, i + 1024);
			  }
			  else {
				  msg11.body() = b1.substr(i, i + (file_size % 1024));
			  }
			  msg11.contentLength(msg11.body().size());
			  msg11.attribute("version", "In-progress");

			  client.connect("localhost", 8080);
			  std::cout << "\n--Posting message to localhost:8080:";
			  msg11.show();
			  Utilities::putline();

			  HttpMessage<HttpReply> reply11 = client.postMessage(msg11);
			  std::cout << "\n--Received reply:";
			  reply11.show();
			  Utilities::putline();

			  if (file_size >1024) {
				  i += 1024;
				  file_size -= 1024;
			  }
			  else {
				  i += (file_size % 1024);
				  file_size -= (file_size % 1024);
			  }
			  
		  }
	  }
	  else {

		  HttpMessage<HttpRequest> msg11;
		  msg11.type().command(HttpRequest::PUT);
		  msg11.action("File CheckIn");
		  msg11.type().fileSpec(reply1.body().toString().substr(reply1.body().toString().find_last_of(":") + 2));
		  msg11.body() = b1;
		  msg11.contentLength(msg11.body().size());
		  msg11.attribute("version", "In-progress");

		  client.connect("localhost", 8080);
		  std::cout << "\n--Posting message to localhost:8080:";
		  msg11.show();
		  Utilities::putline();

		  HttpMessage<HttpReply> reply11 = client.postMessage(msg11);
		  std::cout << "\n--Received reply:";
		  reply11.show();
		  Utilities::putline();
	  }
	  
  }
  inFile.close();


  HttpMessage<HttpRequest> msg12;
  msg12.type().command(HttpRequest::PUT);
  msg12.action("File CheckIn");
  msg12.type().fileSpec("Graph.cpp");
  msg12.attribute("version", "New");

  client.connect("localhost", 8080);
  std::cout << "\n--Posting message to localhost:8080:";
  msg12.show();
  Utilities::putline();

  HttpMessage<HttpReply> reply12 = client.postMessage(msg12);
  std::cout << "\n--Received reply:";
  reply12.show();
  Utilities::putline();
  
  inFile.open(client.clientPath + "Graph.cpp");
  if (!inFile) {
	  std::cout << "\nUnable to open a file";
  }
  else {
	  std::ifstream in(client.clientPath + "Graph.cpp");
	  std::stringstream b;
	  b << in.rdbuf();
	  std::string b1 = b.str();
	  std::cout << b1.size();

	  if (b1.size() > 1024) {
		  size_t file_size = b1.size();
		  int i = 0;
		  while (file_size > 0) {
			  HttpMessage<HttpRequest> msg11;
			  msg11.type().command(HttpRequest::PUT);
			  msg11.action("File CheckIn");
			  msg11.type().fileSpec(reply12.body().toString().substr(reply12.body().toString().find_last_of(":") + 2));
			  if (file_size > 1024) {
				  msg11.body() = b1.substr(i, i + 1024);
			  }
			  else {
				  msg11.body() = b1.substr(i, i + (file_size % 1024));
			  }
			  msg12.contentLength(msg12.body().size());
			  msg11.attribute("version", "In-progress");

			  client.connect("localhost", 8080);
			  std::cout << "\n--Posting message to localhost:8080:";
			  msg11.show();
			  Utilities::putline();

			  HttpMessage<HttpReply> reply11 = client.postMessage(msg11);
			  std::cout << "\n--Received reply:";
			  reply11.show();
			  Utilities::putline();

			  if (file_size >1024) {
				  i += 1024;
				  file_size -= 1024;
			  }
			  else {
				  i += (file_size % 1024);
				  file_size -= (file_size % 1024);
			  }

		  }
	  }
	  else {

		  HttpMessage<HttpRequest> msg11;
		  msg11.type().command(HttpRequest::PUT);
		  msg11.action("File CheckIn");
		  msg11.type().fileSpec(reply12.body().toString().substr(reply12.body().toString().find_last_of(":") + 2));
		  msg11.body() = b1;
		  msg11.contentLength(msg11.body().size());
		  msg11.attribute("version", "In-progress");

		  client.connect("localhost", 8080);
		  std::cout << "\n--Posting message to localhost:8080:";
		  msg11.show();
		  Utilities::putline();

		  HttpMessage<HttpReply> reply11 = client.postMessage(msg11);
		  std::cout << "\n--Received reply:";
		  reply11.show();
		  Utilities::putline();
	  }

  }
  inFile.close();


  HttpMessage<HttpRequest> msg13;
  msg13.type().command(HttpRequest::PUT);
  msg13.action("File CheckIn");
  msg13.type().fileSpec("Graph.cpp");
  msg13.attribute("version", "New");

  client.connect("localhost", 8080);
  std::cout << "\n--Posting message to localhost:8080:";
  msg13.show();
  Utilities::putline();

  HttpMessage<HttpReply> reply13 = client.postMessage(msg13);
  std::cout << "\n--Received reply:";
  reply13.show();
  Utilities::putline();

  inFile.open(client.clientPath + "Graph.cpp");
  if (!inFile) {
	  std::cout << "\nUnable to open a file";
  }
  else {
	  std::ifstream in(client.clientPath + "Graph.cpp");
	  std::stringstream b;
	  b << in.rdbuf();
	  std::string b1 = b.str() + "\n	//Newest Version";
	  std::cout << b1.size();

	  if (b1.size() > 1024) {
		  size_t file_size = b1.size();
		  int i = 0;
		  while (file_size > 0) {
			  HttpMessage<HttpRequest> msg11;
			  msg11.type().command(HttpRequest::PUT);
			  msg11.action("File CheckIn");
			  msg11.type().fileSpec(reply13.body().toString().substr(reply13.body().toString().find_last_of(":") + 2));
			  if (file_size > 1024) {
				  msg11.body() = b1.substr(i, i + 1024);
			  }
			  else {
				  msg11.body() = b1.substr(i, i + (file_size % 1024));
			  }
			  msg11.contentLength(msg11.body().size());
			  msg11.attribute("version", "In-progress");

			  client.connect("localhost", 8080);
			  std::cout << "\n--Posting message to localhost:8080:";
			  msg11.show();
			  Utilities::putline();

			  HttpMessage<HttpReply> reply11 = client.postMessage(msg11);
			  std::cout << "\n--Received reply:";
			  reply11.show();
			  Utilities::putline();

			  if (file_size >1024) {
				  i += 1024;
				  file_size -= 1024;
			  }
			  else {
				  i += (file_size % 1024);
				  file_size -= (file_size % 1024);
			  }

		  }
	  }
	  else {

		  HttpMessage<HttpRequest> msg11;
		  msg11.type().command(HttpRequest::PUT);
		  msg11.action("File CheckIn");
		  msg11.type().fileSpec(reply13.body().toString().substr(reply13.body().toString().find_last_of(":") + 2));
		  msg11.body() = b1;
		  msg11.contentLength(msg11.body().size());
		  msg11.attribute("version", "In-progress");

		  client.connect("localhost", 8080);
		  std::cout << "\n--Posting message to localhost:8080:";
		  msg11.show();
		  Utilities::putline();

		  HttpMessage<HttpReply> reply11 = client.postMessage(msg11);
		  std::cout << "\n--Received reply:";
		  reply11.show();
		  Utilities::putline();
	  }

  }


  //3. CheckOut file
  std::cout << "\nOption 3";

  HttpMessage<HttpRequest> msg3;
  msg3.type().command(HttpRequest::GET);
  msg3.action("File CheckOut");
  msg3.type().fileSpec("Graph.h");
  msg3.attribute("version", "latest");

  client.connect("localhost", 8080);
  std::cout << "\n--Posting message to localhost:8080:";
  msg3.show();
  Utilities::putline();

  HttpMessage<HttpReply> reply3 = client.postMessage(msg3);
  std::cout << "\n--Received reply:";
  reply3.show();
  Utilities::putline();

  if (reply3.body().toString().empty()) {
	  std::cout << "\nFile Not Found";
  }
  else {
	  std::ofstream outfile;
	  outfile.open(client.clientPath + reply3.attributes().at("filename"));
	  outfile << reply3.body().toString();
	  outfile.close();
  }

  HttpMessage<HttpRequest> msg33;
  msg33.type().command(HttpRequest::GET);
  msg33.action("File CheckOut");
  msg33.type().fileSpec("Graph.cpp");
  msg33.attribute("version", "1");

  client.connect("localhost", 8080);
  std::cout << "\n--Posting message to localhost:8080:";
  msg33.show();
  Utilities::putline();

  HttpMessage<HttpReply> reply33 = client.postMessage(msg33);
  std::cout << "\n--Received reply:";
  reply33.show();
  Utilities::putline();

  if (reply33.body().toString().empty()) {
	  std::cout << "\nFile Not Found";
  }
  else {
	  std::ofstream outfile;
	  outfile.open(client.clientPath + reply33.attributes().at("filename"));
	  outfile << reply33.body().toString();
	  outfile.close();
  }


  //4. Browse
  std::cout << "\nOption 4";
  HttpMessage<HttpRequest> msg4;
  msg4.type().command(HttpRequest::GET);
  msg4.action("GetRepoContent");

  client.connect("localhost", 8080);
  std::cout << "\n--Posting message to localhost:8080:";
  msg4.show();
  Utilities::putline();

  HttpMessage<HttpReply> reply4 = client.postMessage(msg4);
  std::cout << "\n--Received reply:";
  reply4.show();
  Utilities::putline();

  //Option 5
  std::cout << "\nOption 5";

  HttpMessage<HttpRequest> msg5;
  msg5.type().command(HttpRequest::GET);
  msg5.action("View");
  msg5.type().fileSpec("Graph.cpp");
  msg5.attribute("version", "latest");
  client.connect("localhost", 8080);
  std::cout << "\n--Posting message to localhost:8080:";
  msg5.show();
  Utilities::putline();

  HttpMessage<HttpReply> reply5 = client.postMessage(msg5);
  std::cout << "\n--Received reply:";
  reply5.show();
  Utilities::putline();

  //Option 7
  std::cout << "\nOption 7";

  HttpMessage<HttpRequest> msg7;
  msg7.type().command(HttpRequest::DELETE);
  msg7.action("Delete");
  msg7.type().fileSpec("Graph.cpp");
  msg7.attribute("version", "all");
  client.connect("localhost", 8080);
  std::cout << "\n--Posting message to localhost:8080:";
  msg7.show();
  Utilities::putline();

  HttpMessage<HttpReply> reply7 = client.postMessage(msg7);
  std::cout << "\n--Received reply:";
  reply7.show();
  Utilities::putline();


  std::cout << "\n\n";

  std::cout << "\n --------------------\n  press key to exit: \n --------------------";
  std::cout.flush();
  std::cin.get();
}
