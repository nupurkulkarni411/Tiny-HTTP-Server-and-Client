#pragma once
/////////////////////////////////////////////////////////////////////////
// HttpServer.h - Provides HTTP Message service                        //
// ver 1.0                                                             //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2018           //
// Application: OOD Demo                                               //
// Platform:    Visual Studio 2017, Dell XPS 8920, Windows 10 pro      //
/////////////////////////////////////////////////////////////////////////
/*
*  Processor Operations:
* -----------------------
* This package implements an HttpServer class that receives HTTP messages
* from multiple concurrent clients and replies to each.
* - Server message processing is defined by a ClientHandler functor,
*   which each application will tailor to define server operations.
* - HttpMessages are defined in a separate Message package.
* - The default processing provided here will accept and display messages
*   from Chrome, FireFox, and Edge.
*
*  Required Files:
* -----------------
*   HttpServer.h, HttpServer.cpp
*   HttpClient.h, HttpClient.cpp
*   Message.h, Message.cpp
*   Sockets.h, Sockets.cpp,
*   Cppll-BlockingQueue.h
*   Logger.h, Logger.cpp
*   Utilities.h, Utilities.cpp
*
*  Maintenance History:
* ----------------------
*   ver 1.0 : 07 Jan 2017
*   - first release
*
*/
#include <functional>
#include "../Message/Message.h"
#include "../Sockets/Sockets.h"
#include "../HttpCommCore/HttpCommCore.h"

namespace HttpCommunication
{
  /////////////////////////////////////////////////////////////////////
  // HttpServerCore class
  // - Instances are not directly created by the application.
  // - They are created by a ClientHandler instance at the beginning
  //   of its operator() method, e.g., is created by each thread that
  //   handles a client.
  // - This class has little state, inherited from HttpCommCore, so is 
  //   inexpensive to create
  //
  class HttpServerCore : public HttpCommCore
  {
  public:
    using RequestMsg = HttpMessage<HttpRequest>;
    using ReplyMsg   = HttpMessage<HttpReply>;
    using MessageProcessType = std::function < ReplyMsg(RequestMsg&)>;

    HttpServerCore(Sockets::Socket* pSocket) : HttpCommCore(pSocket) {}
    HttpMessage<HttpRequest> getMessage();
    void postMessage(HttpMessage<HttpReply> msg);
    HttpMessage<HttpReply> doProcessing(
      MessageProcessType proc, 
      HttpMessage<HttpRequest>& msg
    );
    virtual ~HttpServerCore() {}
  };

  /////////////////////////////////////////////////////////////////////
  // ClientHandler class
  // - defines processing for each server thread, created when a client connects
  // - instances are given, by the SocketListener instance, to a client handling 
  //   thread
  // - Has default processing, but that may be changed by the application
  // - Operations are: read message, process message, send reply message

  class ClientHandler
  {
  public:
    void operator()(Sockets::Socket socket);
  };
  
  /////////////////////////////////////////////////////////////////////
  // HttpServer class
  // - A single instance is created by the application.
  // - Instances start socket listener with an appropriate port,
  //   IP version Socket::IP4 or Socket::IP6, and client handler instance
  //
  class HttpServer
  {
  public:
    HttpServer(size_t port, Sockets::Socket::IpVer ipv) : socketListener(port, ipv) {}
    template <typename ClientHandlerType>
    bool start(ClientHandlerType& co)
    {
      return socketListener.start(co);
    }
  private:
    Sockets::SocketSystem ss;
    Sockets::SocketListener socketListener;
  };
}
