
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define PORT 8080;

int main()
{
	int clientSock;
	char buffer[1024];
	struct sockaddr_in serverAddr;
	
	clientSock = socket(AF_INET,SOCK_DGRAM,0);
	if(clientSock < 0)
	{
		printf("Socket could not be created ");
		return 0;
	}
	printf("\nSocket created ...");
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = PORT;
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	while(1)
	{
		bzero(buffer,sizeof(buffer));
		printf("\nEnter the message to send : ");
		gets(buffer);
		sendto(clientSock,buffer,sizeof(buffer),0,(struct sockaddr*)&serverAddr,sizeof(serverAddr));
		bzero(buffer,sizeof(buffer));
		recvfrom(clientSock,buffer,1024,0,NULL,NULL);
		printf("\nTime stamp %02d:%02d:%02d",buffer[1],buffer[2],buffer[3]);
	}
	
	
	
	
}
