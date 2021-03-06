//
// Summary: server core source code.
//
// Author: Tony.
// Email: tonyjobmails@gmail.com.
// Last modify: 2012-08-27 15:47:53.
// File name: tcp_socket.h
//
// Description: 
// Define class TCPSocket.
// TCPSocket is a wrapper of socket and it only supports TCP connection.
//

#ifndef __CORE__TCP__SOCKET__H
#define __CORE__TCP__SOCKET__H

#include <sys/socket.h>

#include <string>

#include "core/inet_address.h"
#include "core/base/noncopyable.h"
#include "core/base/types.h"

namespace core {

class TCPSocket : public Noncopyable {
 public:
  explicit TCPSocket(int socket = -1);
  virtual ~TCPSocket();

  inline int GetSockfd() const { return this->socket_; }

  // Create a socket.
  bool CreateSocket(bool reuse = true);

  // Connect to a server using server address - "ip" and server port - "port".
  bool Connect(const InetAddress &address);

  // Bind IP and port.
  bool Bind(const InetAddress &address);

  // Listen the socket.
  bool Listen(int max_connection);

  // Check for a new connection, and save it's informations to these arguments.
  int Accept(InetAddress &address);

  // Shutdown the socket according to the argument - shut_flag.
  bool Shutdown(int shut_flag);

  // Close the socket.
  bool Close();

  // Check link available.
  inline bool CheckAvailable() const { return this->link_available_; }
  // Set link available/unavailable.
  inline void SetAvailable() { this->link_available_ = true; }
  inline void SetUnavailable() { this->link_available_ = false;}

  // Nonblock pattern.
  bool SetNonblock();

  // Send/Receive.
  inline int Send(const char *message, int size) {
    return ::send(this->socket_, message, size, MSG_NOSIGNAL);
  }
  inline int Receive(char *message, int max_size) {
    return ::recv(this->socket_, message, max_size, MSG_NOSIGNAL);
  }

 protected:
  int socket_;
  bool link_available_;
  bool nonblocking_;
};

}  // namespace core

#endif  // __CORE__TCP__SOCKET__H

