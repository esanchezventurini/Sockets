/*
 ============================================================================
 Name        : Servidor.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 Para usarlo, debe conectarse alguien al servidor desde la consola usando "nc localhost numeroPuerto"
 */

#include "Bibliotecas.h"

int main(void) {
	struct sockaddr_in direccionServidor;

	direccionServidor.sin_family = AF_INET;
	direccionServidor.sin_addr.s_addr = inet_addr("127.0.0.1");
	direccionServidor.sin_port = htons(8077);


	int servidor = socket(AF_INET ,SOCK_STREAM,0);

	int verdadero = 1;
	setsockopt(servidor, SOL_SOCKET, SO_REUSEADDR, &verdadero, sizeof(verdadero));

	if(bind(servidor,(void*)&direccionServidor,sizeof(direccionServidor)) != 0){
		perror("Falla en bind");
		return -1;
	}

	if(listen(servidor, 10) == -1){
		perror("Falla en listen");
		return -1;
	}

	struct sockaddr_in direccionCliente;
	int tamanioDireccion = sizeof(struct sockaddr_in);

	int cliente = accept(servidor, (void*) &direccionCliente, &tamanioDireccion);
    printf("Conectado con: %d",cliente);

	while(1){
		char mensaje[1000];
		scanf("\n %s", mensaje);
		send(cliente, mensaje, strlen(mensaje), 0);
	}

}






