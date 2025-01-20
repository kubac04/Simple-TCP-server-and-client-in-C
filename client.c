#include<stdio.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/socket.h>

#include<netinet/in.h>


int main(int argc, char*argv[]){
    // Utworzenie gniazka
    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    // specify an address for socket , deklarowanie truktury 
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    if ( connection_status == -1){
        printf("There was an error making a connection to remote socket \n");
    }
    // recive data
    char server_respones[256];
    recv(network_socket, &server_respones, sizeof(server_respones), 0);

    // print out the servers response 
    printf("The server repsonse is : %s\n", server_respones);

    //close the socket
    close(network_socket);

    return 0;

}