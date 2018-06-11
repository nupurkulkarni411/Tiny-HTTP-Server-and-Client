//#ifndef _HTTP_COMM_CORE_
//#define _HTTP_COMM_CORE_

#pragma once

#include <functional>
#include "../Message/Message.h"
#include "../Sockets/Sockets.h"

using namespace Sockets;

namespace HttpCommunication
{
	class HttpCommCore
	{
	public:
		HttpCommCore(Sockets::Socket* pSocket) : pSocket_(pSocket) {};
		virtual ~HttpCommCore() {};
		template <typename T>
		HttpMessage<T> getMessage();

		template<typename T>
		void postMessage(HttpMessage<T> msg);

	protected:
		Sockets::Socket* pSocket_;
	};

	//----< pull HttpMessage from socket >---------------------

	template<typename T>
	HttpMessage<T> HttpCommCore::getMessage()
	{
		// read HTTP message header lines
		Socket& socket = *pSocket_;
		std::string msgString;
		while(socket.validState()) {
			std::string temp = socket.recvString('\n');
			msgString += temp;
			if(temp.length() < 3 || !socket.validState())
				break;
		}

		HttpMessage<T> msg = HttpMessage<T>::fromString(msgString);

		size_t bodyLen = msg.contentLength();
		HttpMessageBody body;
		std::string temp;
		if (bodyLen > 0) {
			body.size(bodyLen);
			socket.recv(bodyLen, (Socket::byte *) (body.data().data()));
		}
		msg.body() = body;
		return msg;
	}

	//----< push HttpMessage into socket >--------------------------

	template<typename T>
	void HttpCommCore::postMessage(HttpMessage<T> msg)
	{
		std::string sendHeader = msg.toHeaderString();
		pSocket_->send(sendHeader.size(), (Socket::byte *)sendHeader.c_str());
		size_t bodyLen = msg.contentLength();
		HttpMessageBody body = msg.body();
		pSocket_->send(bodyLen, (Socket::byte*)body.data().data());
	}
}

//#endif	// _HTTP_COMM_CORE_
