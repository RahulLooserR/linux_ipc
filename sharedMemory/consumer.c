/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : consumer.c
 * Created on    : 26-03-2019
 * Last modified : Tuesday 26 March 2019 02:20:25 PM IST
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

	shm_fd = shm_open(name, O_RDONLY, 0666);
	printf("fd: %d\n", shm_fd);

	ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

	printf("%s", (char*)ptr);
	shm_unlink(name);

	return 0;
}
