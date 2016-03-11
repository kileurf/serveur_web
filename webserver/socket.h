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
void initialiser_signaux(void);
void traitement_signal(int sig);
void hand(int sig);
#endif
