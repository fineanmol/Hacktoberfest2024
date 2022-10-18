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
int main() {
	int sockfd;
	struct sockaddr_in server;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
		printf("Socket Creation Failed\n");
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	if (connect(sockfd, (struct sockaddr *)&server, sizeof(struct sockaddr)) < 0)
		printf("Connection with the Server Failed\n");
	char username[30], password[30];
	printf("Enter Username: ");
	scanf("%s", username);
	printf("Enter Password: ");
	scanf("%s", password);
	if (send(sockfd, username, sizeof(username), 0) < 0)
        	printf("Failed to Send the Message\n");
        if (send(sockfd, password, sizeof(password), 0) < 0)
        	printf("Failed to Send the Message\n");
	return 0;
}
