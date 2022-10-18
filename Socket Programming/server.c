// Write a program in C using TCP where the server contains userID, username, and password of 5 users using structure. Now the client sends userID and password to the server. If both userID and password match with the available userID and password then the server sends a message as ‘Login Successful’ otherwise, it sends a message as ‘Login Unsuccessful’.

// Nishant Giri (github.com/nishant-giri)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define PORT 8080
#define BACKLOG 10
struct Account {
	int userID;
	char username[30];
	char password[30];
};
int main() {
	int sockfd, newfd;
	struct Account acc[5];
	struct sockaddr_in server, client;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
		printf("Socket Creation Failed\n");
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	int b = bind(sockfd, (struct sockaddr *)&server, sizeof(struct sockaddr));
	if (b == -1)
		printf("Socket Binding Failed\n");
	if (listen(sockfd, BACKLOG) < 0)
		printf("Server Listening Failed\n");
	for (int i = 0; i < 5; i++) {
		printf("Enter User ID for User %d: ", i + 1);
		scanf("%d", &acc[i].userID);
		printf("Enter Username for User %d: ", i + 1);
		scanf("%s", acc[i].username);
		printf("Enter Password for User %d: ", i + 1);
		scanf("%s", acc[i].password);
		printf("\n");
	}
	int s = sizeof(client);
	newfd = accept(sockfd, (struct sockaddr *)&client, &s);
	if (newfd < 0)
		printf("Failed to Accept the Message\n");
	char recvusername[30], recvpassword[30];
	if (recv(newfd, recvusername, sizeof(recvusername), 0) < 0)
		printf("Failed to Receive the Message\n");
	if (recv(newfd, recvpassword, sizeof(recvpassword), 0) < 0)
		printf("Failed to Receive the Message\n");
	int flag = 0;
	for (int i = 0; i < 5; i++) {
		if ((strcmp(recvusername, acc[i].username) == 0) && (strcmp(recvpassword, acc[i].password) == 0)) {
			printf("Login Successful\n");
			flag++;
			exit(0);
		}
	}
	if (flag == 0)
		printf("Login Unsuccessful\n");
	return 0;
}
