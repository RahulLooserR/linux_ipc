/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : signal_handler2.c
 * Created on    : 26-03-2019
 * Last modified : Tuesday 26 March 2019 09:47:04 AM IST
 * Description   : 
 * ***********************************************************************/


#include <unistd.h>     /* standard unix functions, like getpid()       */
#include <sys/types.h>  /* various type definitions, like pid_t         */
#include <signal.h>     /* signal name macros, and the kill() prototype */
#include <stdio.h>

int main ()
{	
	pid_t pid = getpid();
	int i = 0;

	while(i < 100){
		printf ("hi\n");
		i++;
		sleep(1);
		
		// signal to kill current pid, using kill function
		if (i == 10)
			kill(pid, SIGSTOP);
	}
	
	return 0;
}
