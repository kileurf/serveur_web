#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include "socket.h"
int status;
int pid;
void hand(int sig) {
    printf(" Entree dans le handler \n");
    if (pid == -1) /* suppression du fils zombi */
    {
         perror("wait handler ");
         return ;
    }
return;
}
int main(void){
	int socket_serveur=creer_serveur(8080);
	initialiser_signaux();
	//int status;
	int socket_client;
	//signal(SIGCHLD, hand);
	while (1) {
		socket_client = accept ( socket_serveur , NULL , NULL );
		if ( socket_client == -1){
			perror ( " accept " ); /* traitement d ’ erreur */
		}
		const char * message_bienvenue = "La sortie c'est sur la petite croix (rouge) merci 			d'appuyer dessus.\n Nutella et Caramel\n J'vous aimes putain";
		//int pid;
		if((pid=fork())==0){
			char *buf = malloc(sizeof(char)*80);
			write ( socket_client , message_bienvenue , strlen		(message_bienvenue));

			FILE *f = fdopen(socket_client, "r+");
 			do {fgets(buf, sizeof(buf),f);
 				printf("%s",buf);
 				fflush(stdout);
 				write ( socket_client, buf , strlen (buf));
			}while(buf[0]!='.' && buf[1]!='q');
 			free(buf);	
			close(socket_client);
			exit(0);
		}
		
    		

        	   
	}
	
	return 0;
}
