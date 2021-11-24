#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include <stdlib.h>
#include <string.h>
struct sigaction act;
void sighandler(int signum)
{
	if(signum==2)
	{
		printf("\nInside SIGINT Handler Function\n");
		printf("Interrupt SIGINT received.\n"); 
		printf("Do you really want to quit (y|n)?\n");
		char yn;
		scanf(" %c", &yn);
		if(yn =='y')
			exit(0);
	}
	else
	{
		printf("\nInside SIGTERM Handler Function\n");
		printf("Interrupt SIGINT received.\n"); 
		printf("Do you really want to quit (y|n)?\n");
		char yn;
		scanf(" %c", &yn);
		if(yn =='y')
			exit(0);
	}
}
int main(){
	signal(SIGINT,sighandler); // Register signal handler
	signal(SIGTERM,sighandler);
	printf("I am %lu\n", (unsigned long)getpid());
	for(int i=1;;i++){    //Infinite loop
		printf("%d : Inside main function\n",i);
		sleep(1);  // Delay for 1 second
	}   
	return 0;
}
