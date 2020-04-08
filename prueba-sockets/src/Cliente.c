/*
 ============================================================================
 Name        : prueba-sockets.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Se debe usar "nc -l numeroPuerto" para recibir los mensajes de este cliente

 */

#include "Bibliotecas.h"

int main(int argc, char** argv){

	struct sockaddr_in direccionServidor;
	direccionServidor.sin_family = AF_INET;
	direccionServidor.sin_addr.s_addr = inet_addr("127.0.0.1");
	direccionServidor.sin_port = htons(8081);

	int cliente = socket(AF_INET ,SOCK_STREAM,0);

	if(connect(cliente,(void*)&direccionServidor,sizeof(direccionServidor)) != 0){
		perror("No se pudo conectar");
		return 1;
	}

	printf("Servidor conectado");

	while(1){
		char mensaje[1000];
		scanf("%s", mensaje);
		send(cliente, mensaje, strlen(mensaje), 0);
	}

	return 0;
}
