//Orphan process

#include<stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main() 
{ 
	// Create a child process	 
	int pid = fork(); 

	if (pid > 0) 
		printf("in parent process"); 

	else if (pid == 0) 
	{ 
		sleep(30); 
		printf("in child process"); 
	} 

	return 0; 
} 
