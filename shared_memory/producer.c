/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : producer.c
 * Created on    : 26-03-2019
 * Last modified : Tuesday 26 March 2019 12:56:24 PM IST
 * Description   : 
 * ***********************************************************************/

#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */	
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define SIZE 4096

int main()
{
	int shm_fd; 	// file descriptor for shm_open
	void* ptr;		// address returned by mmap
	const char* name = "shared_Memory"; // name of shared memory
	char str1[] = "hello";
	char str2[] = "world";

	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
	printf("fd: %d\n", shm_fd);

	ftruncate(shm_fd, SIZE);

	ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);

	sprintf(ptr, "%s", str1);
	ptr += strlen(str1);

	sprintf(ptr,"%s", str2);
	ptr += strlen(str2);

	return 0;
}
