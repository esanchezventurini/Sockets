/*
 * Bibliotecas.h
 *
 *  Created on: 7 abr. 2020
 *      Author: utnso
 */

#ifndef BIBLIOTECAS_H_
#define BIBLIOTECAS_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>

#endif /* BIBLIOTECAS_H_ */

/*
pthread_t enviarMensajes;
pthread_t recibirMensajes;
void enviarMensajes(int *cliente){
	while(1){
		char mensaje[1000];
		scanf("%s \n", mensaje);
		send(*cliente, mensaje, strlen(mensaje), 0);
	}
}
pthread_create(&enviarMensajes , NULL , (void*)enviarMensajes , &cliente);
*/
