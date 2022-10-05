#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<unistd.h>

void main()
{
    int sd,data,len;
    struct sockaddr_in server,cli;
    char buffer[100];
    pid_t childpid;
    sd = socket(AF_INET,SOCK_STREAM,0);
    if(sd<0)
    {
        perror("Socket not created\n");
        exit(1);
    }
    else
    {
        printf("Socket created\n");
        server.sin_family=AF_INET;
        server.sin_port=htons(8080);
        server.sin_addr.s_addr=htonl(INADDR_ANY);
        if(bind(sd,(struct sockaddr*)&server,sizeof(server))<0)
        {
            perror("Error in binding");
            exit(1);
        }
        else
        {
            printf("Binding done\n");
            listen(sd,5);
            len = sizeof(cli);
            while (1)
            {
                data = accept(sd,(struct sockaddr*)&cli,&len);
                if(data<0)
                {
                    perror("Error accepting connection");
                    exit(1);
                }
                else
                {
                    printf("Connection accepted\n");
                    if((childpid = fork()) == 0)
                    {
                        close(sd);
                    }
                    else
                    {
                        if(recvfrom(data,buffer,sizeof(buffer),0,NULL,NULL)<0)
                        {
                            perror("Error receiving data");
                            exit(1);
                        }
                        else
                            printf("Message received : %s",buffer);
                        close(data);
                    }
                }
            }
        }
    }
}

