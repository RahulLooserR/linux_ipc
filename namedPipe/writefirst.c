/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : writefirst.c
 * Created on    : 26-03-2019
 * Last modified : Tuesday 26 March 2019 06:24:52 PM IST
 * Description   : 
 * ***********************************************************************/
 
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX 256

int main()
{
	int fd;								// file descriptor
	char readBuf[MAX], writeBuf[MAX];   // buffer to read and write
	const char* PATH = "/tmp/new_fifo"; // path for creating fifo

	if(!mkfifo(PATH, 0666)){
		printf("Error creating fifo\n");
		return 0;
	}

	while(1){
		// opening fifo in write only mode
		fd = open(PATH, O_WRONLY);
		
		// getting input from user
		fgets(writeBuf, MAX, stdin);
	
		// writing to fifo using buffer
		write(fd, writeBuf, strlen(writeBuf) + 1);
		close(fd);
		
		// opening fifo in read only mode
		fd = open(PATH, O_RDONLY);
		// reading fifo
		read(fd, readBuf, sizeof(readBuf));
		printf("user2 : %s\n", readBuf);
		close(fd);
	}


	return 0;
}
