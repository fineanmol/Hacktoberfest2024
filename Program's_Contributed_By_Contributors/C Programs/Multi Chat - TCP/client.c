#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char**argv)
{
    struct sockaddr_in server;
    int sd,len;
    char *servaddr;
    char buffer[100];
    if(argc<2)
    {
        printf("usage <ip address>\n");
        exit(0);
    }
    servaddr=argv[1];
    sd = socket(AF_INET,SOCK_STREAM,0);
    if(sd<0)
    {
        perror("Socket cannot be created\n");
        exit(1);
    }
    else
    {
        printf("socket created.\n");
        server.sin_family=AF_INET;
        server.sin_port=htons(8080);
        server.sin_addr.s_addr=inet_addr(servaddr);
        if(connect(sd,(struct sockaddr*)&server,sizeof(server))<0)
        {
            perror("Connection not established");
            exit(1);
        }
        else
        {
            printf("Connection Established\n");
            printf("Enter messages:");
            fgets(buffer,sizeof(buffer),stdin);
            if(sendto(sd,buffer,sizeof(buffer),0,(struct sockaddr*)&server,sizeof(server))<0)
            {
                perror("Error sending data");
                exit(1);
            }
        }
        close(sd);
        printf("Connection Closed\n");
    }
}