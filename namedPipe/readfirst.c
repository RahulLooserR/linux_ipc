/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : readfirst.c
 * Created on    : 26-03-2019
 * Last modified : Tuesday 26 March 2019 05:38:34 PM IST
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
	int fd; 
	char readBuf[MAX], writeBuf[MAX];
	const char* PATH = "/tmp/new_fifo";

	/*	if(!mkfifo(PATH, 0666)){
		printf("Error creating fifo\n");
		return 0;
		}   
	 */

	while(1){
		fd = open(PATH, O_RDONLY);

		read(fd, readBuf, sizeof(readBuf));
		printf("user1 : %s\n", readBuf);
		close(fd);	

		fd = open(PATH, O_WRONLY);

		fgets(writeBuf, MAX, stdin);

		write(fd, writeBuf, strlen(writeBuf) + 1);
		close(fd);

	}

	return 0;
}
