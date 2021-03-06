// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main(void)
{
		int p[2];
		char buff[256];
		
		if(pipe(p) < 0){
			exit(1);
		}
		int rc = fork();

		if (rc < 0){
			exit(1);
		} else if (rc == 0){
			write(p[1], msg1, MSGSIZE);
    	write(p[1], msg2, MSGSIZE);
    	write(p[1], msg3, MSGSIZE);
		} else {
			
			for (int i = 0; i < 3; i++){
				read(p[0], buff, MSGSIZE);
				printf("%s\n", buff);
			}
		}

    
    return 0;
}
