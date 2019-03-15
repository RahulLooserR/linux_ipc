/* ****************************************************************************
 * Created by : Rahul Kumar Nonia
 * File name : unidirectional.c
 * Created on : 15-03-2019
 * Last modified : Friday 15 March 2019 07:16:47 PM IST
 * Description : Linux ipc mechanism using pipes, 
 *				one end to write other end to read.
 * ***************************************************************************/

#include <stdio.h>
#include <unistd.h>


int main()
{
	int pipeFD[2];
	int returnStatus;
	int pid;
	char writeMsg[2][10] = {"hi", "hey"};
	char readMsg[10];

	returnStatus = pipe (pipeFD);	 

	if (returnStatus == -1) {
		printf ("unable to create pipe.\n");
		return 1;
	}
    
	pid = fork ();  // creating process

	// child process
	if (pid == 0) {
		read (pipeFD[0], readMsg, sizeof (readMsg));
		printf ("child process reading the pipe, msg1 : %s\n", readMsg);
		read (pipeFD[0], readMsg, sizeof (readMsg));
		printf ("child process reading the pipe, msg2 : %s\n", readMsg);

	}
	// parent process
	else {
		printf ("Parent process writing to pipe, msg1 : %s\n", writeMsg[0]);
		write (pipeFD[1], writeMsg, sizeof(writeMsg));
		printf ("Parent process writing to pipe, msg2 : %s\n", writeMsg[1]);
		write (pipeFD[1], writeMsg, sizeof(writeMsg));

	}

	return 0;
}
