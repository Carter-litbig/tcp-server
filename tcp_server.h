#pragma once
// tcpsrv
#include <stdint.h>
#include <string>

#include "connection_manager.h"
#include "client_db.h"
#include "client_service.h"

#include "tcp_client.h"

<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 7aae7196fac60570b89d7991884599e1ec7b55c9
/* assignment_7_1 */
#define TCP_SERVER_INITIALIZED (1)
#define TCP_SERVER_RUNNING (2)
#define TCP_SERVER_NOT_ACCEPTING_NEW_CONNECTIONS (4)
#define TCP_SERVER_NOT_LISTENING_CLIENTS (8)
#define TCP_SERVER_CREATE_MULTI_THREADED_CLIENT (16)

<<<<<<< HEAD
>>>>>>> 7aae719 (add deleted file)
=======
>>>>>>> 7aae7196fac60570b89d7991884599e1ec7b55c9
/* Notify for application */
#if 0
typedef void (*ClientConnected)(const TcpServer*, const TcpClient);
typedef void (*ClientDisconnected)(const TcpServer*, const TcpClient);
// const TcpServer*, const TcpClient, unsigned char* msg, uint16_t len
typedef void (*ClientReceived)(const TcpServer*, const TcpClient,
                               unsigned char*, uint16_t);
#endif

using ClientConnected = void (*)(const TcpServer*, const TcpClient*);
using ClientDisconnected = void (*)(const TcpServer*, const TcpClient*);
using ClientReceived = void (*)(const TcpServer*, const TcpClient*,
                                unsigned char*, uint16_t);

class TcpServer {
 public:
  uint32_t ip;
  uint16_t port;
  std::string name;

  TcpServer(std::string ip, uint16_t port, std::string name);
  ~TcpServer();

  void Start();
  void Stop();

  void AddClient(TcpClient* client);

  ClientConnected connected;
  ClientDisconnected disconnected;
  ClientReceived received;

  /* Register listeners for application */
  void RegisterListener(ClientConnected, ClientDisconnected, ClientReceived);

  void Display();
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 7aae7196fac60570b89d7991884599e1ec7b55c9

  void SetBit(uint32_t bit);
  void UnSetBit(uint32_t bit);
  bool IsBitSet(uint32_t bit);

  void StopConnectionAcceptance();
  void StartConnectionAcceptance();

  void StopClientService();
  void StartClientService();

  /* assignment_7_2 */
  void CopyClients(std::list<TcpClient*>* list);
<<<<<<< HEAD
>>>>>>> 7aae719 (add deleted file)
=======
>>>>>>> 7aae7196fac60570b89d7991884599e1ec7b55c9

 private:
  ConnectionManager* connection_manager_;
  ClientDB* client_db_;
  ClientService* client_service_;
<<<<<<< HEAD
<<<<<<< HEAD
=======
  uint32_t state;
>>>>>>> 7aae719 (add deleted file)
=======
  uint32_t state;
>>>>>>> 7aae7196fac60570b89d7991884599e1ec7b55c9
};