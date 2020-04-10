/*
 ============================================================================
 Name        : Servidor.c
 Author      : Zeke
 Version     : 1.3
 Copyright   : Your copyright notice
 Description : Servidor de sockets
 ============================================================================

 Para usarlo, debe conectarse alguien al servidor desde la consola usando "nc localhost numeroPuerto"
 */

#include "Bibliotecas.h"

struct cliente_y_servidor{
	int cliente;
	int servidor;
};

void recibirMensajes(struct cliente_y_servidor* datosDeConexion){
	int cliente = datosDeConexion->cliente;
	int servidor = datosDeConexion->servidor;
	char* buffer = malloc(30);
	int conectado = 1;
	while(conectado){
	    	int bytesRecibidos = recv(cliente, buffer, 30, 0);
	    	buffer[bytesRecibidos] = '\0';
	    	if(bytesRecibidos <= 0){
	    		perror("El cliente se ha desconectado");
	      		close(servidor);
	    		close(cliente);
	    		free(buffer);
	    		conectado = 0;
	    	}
	    	else{
	    		printf("Mensaje recibido: %s", buffer);
	    	}
	    }
}

void enviarMensajes(int* cliente){
	while(1){
			char mensaje[1000];
			scanf("\n %s", mensaje);
			send(*cliente, mensaje, strlen(mensaje), 0);
		}
}

int main(void) {
	pthread_t llegadaDeMensajes;
	pthread_t envioDeMensajes;

	struct sockaddr_in direccionServidor;

	direccionServidor.sin_family = AF_INET;
	direccionServidor.sin_addr.s_addr = inet_addr("127.0.0.1");
	direccionServidor.sin_port = htons(8115);


	int servidor = socket(AF_INET ,SOCK_STREAM, 0);

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
	unsigned int tamanioDireccion = sizeof(struct sockaddr_in);

	int cliente = accept(servidor, (void*) &direccionCliente, &tamanioDireccion);
    printf("Conectado con: %d \n",cliente);

    struct cliente_y_servidor infoConexion;
    infoConexion.cliente = cliente;
    infoConexion.servidor = servidor;

    pthread_create(&llegadaDeMensajes , NULL , (void*)recibirMensajes , (void*)&infoConexion);
    pthread_create(&envioDeMensajes, NULL, (void*)enviarMensajes, (void*)&cliente);

	while(1);

}






