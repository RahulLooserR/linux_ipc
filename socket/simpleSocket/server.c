#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 8080


int main ()
{
	struct sockaddr_in sockaddr, server_addr;
	int sock = 0, readVal;

	char* hello = "Hello from client\n";
	char buff[256] = {0};

	// creating socket
	// socket (int domain, int type, int protocol) 
	if ((sock = socket (AF_INET, SOCK_DGRAM, 0)) < 0) {
		printf ("socket creation failed\n");
		return -1;
	}
	

	// bzero can be also used
	memset (&server_addr, 0, sizeof(server_addr));

	// initializing structure with values
	server_addr.sin_family = AF_INET;
	// conversion of host byte order to network byte order
	server_addr.sin_port = htons(PORT);

	server_addr.sin_addr.s_addr = INADDR_ANY;


	// binding the 

	return 0;
}
