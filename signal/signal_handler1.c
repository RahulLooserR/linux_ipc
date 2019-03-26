/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : signla_handler1.c
 * Created on    : 26-03-2019
 * Last modified : Tuesday 26 March 2019 09:22:03 AM IST
 * Description   : 
 * ***********************************************************************/
 
#include <stdio.h>
#include <signal.h>
#include <time.h>

// signal handler function
void signal_handler(int sig)
{
	printf("Signal handler is called \n");
}


int main()
{

	signal(SIGINT, signal_handler);
	
	while(1){
		printf("running\n");
		sleep(1);
	}
		
	return 0;
}
