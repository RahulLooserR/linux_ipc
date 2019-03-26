/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : example1.c
 * Created on    : 26-03-2019
 * Last modified : Tuesday 26 March 2019 10:26:11 AM IST
 * Description   : 
 * ***********************************************************************/


#include <stdio.h> 
#include <signal.h> 
#include <wait.h> 
#include <stdlib.h>
#include <unistd.h>

int val = 10; 
void handler(int sig) 
{ 
	printf("handler called\n");
	val += 5; 
} 
int main() 
{ 
	pid_t pid; 
	signal(SIGCHLD, handler); 
	if ((pid = fork()) == 0) 
	{
		printf ("inside child\n"); 
		val -= 3;
		printf ("%d\n", val); 
		printf ("value decremented\n");
		exit(0); 
	} 
	waitpid(pid, NULL, 0); 
	printf("val = %d\n", val); 
	exit(0); 
} 

