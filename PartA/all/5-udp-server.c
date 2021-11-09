#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int udpSocket, nBytes, i;

    char buﬀer[1024];
    struct sockaddr_in serverAddr, clientAddr;
    struct sockaddr_storage serverStorage;
    socklen_t addr_size, client_addr_size;

    /*Create UDP socket*/
    udpSocket = socket(PF_INET, SOCK_DGRAM, 0);

    /*Configure settings in address struct*/
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(6000);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

    /*Bind socket with address struct*/
    bind(udpSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

    /*Initialize size variable to be used later on*/
    addr_size = sizeof serverStorage;

    while (1) {
        /* Try to receive any incoming UDP datagram. Address and port of
        requesting client will be stored on serverStorage variable */
        nBytes = recvfrom(udpSocket, buﬀer, 1024, 0, (struct sockaddr *)&serverStorage, &addr_size);

        /* print message */
        printf("Message from client:\n\n");
        for(i = 0; i < nBytes - 1; i++)
            printf("%c", buﬀer[i]);
        printf("\n");

        /*Convert message received to uppercase*/
        for(i = 0; i < nBytes - 1; i++)
        buﬀer[i] = toupper(buﬀer[i]);

        /*Send uppercase message back to client, using serverStorage as the address*/
        sendto(udpSocket, buﬀer, nBytes, 0, (struct sockaddr *)&serverStorage, addr_size);
    }

    return 0;
}
