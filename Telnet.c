// Telnet using C sockets.
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h> 
#include <arpa/inet.h> 
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

char *hostname_ret(char* hostnam)
{
	struct hostent *hstnm;
	char * ipad = malloc(100*sizeof(char));
	hstnm = gethostbyname(hostnam);
	struct in_addr **longchange;
	if(hstnm!=NULL)	
	{
		longchange = (struct in_addr **) hstnm->h_addr_list; // list of server addresses
		
		int i=0;
		
		while(longchange[i]!=NULL)
		{
			char* ipval = inet_ntoa(*longchange[i]);
			strcpy(ipad,ipval);
			i++;
		}

		printf("IP resolved: %s\n",ipad );
		return ipad;

	}

	else
	{
		printf("hostname retrival failed\n");
		exit(1);
	}
}

int main(int argc, char *argv[])
{
	//cmd_add = argv[2];
	unsigned int port_no;
	//char sendbuf[200];
	//char recbuf[2000];
	char * ipad = malloc(100*sizeof(char));
	char * hostnam = argv[1];
	const char* ext = "\r\n\r\n";

	if(argc<3)
	{
		port_no = (unsigned int) 3000;
		printf("port assigned 3000\n");
	}
	else
	{

		port_no = atoi(argv[2]);
	}
	// socket connection
	int fd = socket(AF_INET,SOCK_STREAM,0);

	if(fd<0)
	{
		printf("socket connection problem\n" );
		exit(1);
	}

	else
	{
		printf("socket connection initiated\n");
	}


	//printf("%s %d\n",argv[1],port_no );

	//retriving the host name to ip
	ipad = hostname_ret(hostnam);
	//connection structure
	struct sockaddr_in sadd;

	sadd.sin_addr.s_addr = inet_addr(ipad);
	sadd.sin_port = htons(port_no);
	sadd.sin_family = AF_INET;

	int connect_val = connect(fd,(const struct sockaddr *)&sadd,sizeof(sadd));

	if(connect_val<0)
	{
		printf("connection_problem\n" );
		exit(1);
	}

	else
	{
		printf("connected\n" );
	}

	char * recbuf;
	char * sendbuf;
	int send_val,rec_val;
	char * finalstr;

	while(1)
	{
		int f1=0,f2=0;

		if(f1==0)
		{
			printf("<You>: ");
			sendbuf = calloc(200,sizeof(char));
			scanf("%s",sendbuf);

			finalstr = malloc(strlen(sendbuf)+1+8);
			strcpy(finalstr,sendbuf);
			strcat(finalstr,ext);

			send_val = send(fd,finalstr,strlen(finalstr),0);

			if(send_val<0)
			{
				printf("sending failed\n");
				exit(1);
			}

			else
			{
				printf("msg sent\n");
			}

			f2=1;
			f1=1;

			free(sendbuf);
		}

		if(f2==1)
		{
			recbuf = calloc(10000,sizeof(char));
			rec_val = recv(fd,recbuf,2000,0);

			if(rec_val<0)
			{
				printf("recieve failed\n");
				exit(1);
			}

			else
			{
				printf("recieve sucessfull\n");
			}

			printf("%s\n",recbuf );
			printf("\n\n\n\n\n\n");

			f1=0;
			f2=0;

			free(recbuf);
		}
 

	}


	return 0;

}
