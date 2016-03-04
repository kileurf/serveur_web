#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef __SOCKET_H__
#define __SOCKET_H__


int creer_serveur(int port);
#endif
