#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<time.h>
#define PORT 8080;

char* get_time()
{
	time_t T = time(NULL);
	struct tm tm = *localtime(&T);
	char *buff = malloc(80);
	buff[0] = tm.tm_hour;
	buff[1] = ':';
	buff[2] = tm.tm_min;
	buff[3] = ':';
	buff[4] = tm.tm_sec;
	return buff;
}


int main()
{
	int serverSock,ret,len;
	char buffer[1024];
	struct sockaddr_in serverAddr,cliaddr;
	
	serverSock = socket(AF_INET,SOCK_DGRAM,0);
	if(serverSock < 0)
	{
		printf("Socket could not be created ");
		return 0;
	}
	printf("\nSocket created ...");
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = PORT;
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	ret = bind(serverSock,(struct sockaddr*) &serverAddr,sizeof(serverAddr));
	if(ret < 0){
		printf("\nBinding failed");
		return 0;
	}
	printf("\nBinding successfull");
	
	
	
	while(1)
	{
		int n = recvfrom(serverSock,buffer,1024,0,(struct sockaddr*)&cliaddr,&len);
	
		buffer[n] = '\0';
		printf("\nMessage Recivied.. %s\n",buffer);
		if(strncmp("time",buffer,4) == 0){
			printf("\nsending time stamp");
			bzero(buffer,sizeof(buffer));
			strcpy(buffer,get_time());
		}else
		{
			printf("invalid command");
		}
		
		sendto(serverSock,buffer,1024,0,(struct sockaddr*)&cliaddr,sizeof(cliaddr));
		
		
		
	}
	return 0;
	
	
}
