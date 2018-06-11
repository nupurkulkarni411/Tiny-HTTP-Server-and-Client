/////////////////////////////////////////////////////////////////////////
// HttpServer.cpp - Provides HTTP Message service                      //
// ver 1.0                                                             //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2018           //
// Application: OOD Demo                                               //
// Platform:    Visual Studio 2017, Dell XPS 8920, Windows 10 pro      //
/////////////////////////////////////////////////////////////////////////

#include "HttpServer.h"
#include "../Sockets/Sockets.h"
#include "../Logger/Logger.h"
#include "../Utilities/Utilities.h"
#include "../Message/Message.h"
#include "HttpServerProc.h"
#include <string>
#include <iostream>

using namespace Sockets;
using Show = StaticLogger<1>;

namespace HttpCommunication
{
  using RequestMsg = HttpServerCore::RequestMsg;
  using ReplyMsg   = HttpServerCore::ReplyMsg;
  using MessageProcessType = HttpServerCore::MessageProcessType;

  //----< extract message from socket >--------------------------------

  RequestMsg HttpServerCore::getMessage()
  {
    RequestMsg msg = HttpCommCore::getMessage<HttpRequest>();
    return msg;
  }
  //----< push message into socket >-----------------------------------

  void HttpServerCore::postMessage(HttpMessage<HttpReply> reply)
  {
    HttpCommCore::postMessage<HttpReply>(reply);
  }

  //----< helper function for ClientHandler operator() >---------------
  /*
  *  - ReplyMsg makeReplyMessage(RequestMsg msg) 
  *    Defined in HttpServerProc.h
  *
  *  - This function is provided by each application to define
  *    its server processing.
  */

  //----< hook for application defined processing >--------------------

  ReplyMsg HttpServerCore::doProcessing(
    MessageProcessType proc, 
    HttpMessage<HttpRequest>& msg
  )
  {
    return proc(msg);
  }
  //----< defines server processing for each client thread >-----------
  /*
  *  - Client threads are created in Sockets::SocketListener::start(...).
  *  - The SocketListener thread creates an instance of ClientHandler
  *    and a thread that executes that instance.
  */
  void ClientHandler::operator()(Socket socket)
  {
    // The following statement must be the first in every 
    // application defined ClientHandler::operator().

    HttpServerCore server(&socket);

    HttpMessage<HttpRequest> msg = server.getMessage();
    
    std::cout << "\n--received request message:";
    msg.show();
    Utilities::putline();

    // apply application define processing

    HttpMessage<HttpReply> reply = server.doProcessing(makeReplyMessage, msg);
    
    server.postMessage(reply);
    std::cout << "\n--sent reply message:";
    reply.show();
    Utilities::putline();

    // terminate session

    socket.shutDown();
  }
}
//----< server entry point >-----------------------------------------

using namespace HttpCommunication;

int main()
{
  SetConsoleTitle(L"HttpServer");

  Show::attach(&std::cout);
  Show::start();
  Show::title("Http Server started");
  try
  {
    HttpServer server(8080, Socket::IP6);
    ClientHandler cp;
    server.start<ClientHandler>(cp);

    Show::write("\n --------------------\n  press key to exit: \n --------------------");
    std::cout.flush();
    std::cin.get();
  }
  catch (std::exception& exc)
  {
    Show::write("\n  Exeception caught: ");
    std::string exMsg = "\n  " + std::string(exc.what()) + "\n\n";
    Show::write(exMsg);
  }
}