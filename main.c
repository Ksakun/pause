#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sig_catcher(int signo){
	printf("Signal Occur!\n");
}

int main(){
	int pid;
	int status;

	signal(SIGUSR1, sig_catcher);
	
	if( ( pid = fork()) ==0){
		pause();
		printf("Child wake up!\n");
		exit(0);
	}
	else{
		//sleep(1);
		kill( pid, SIGUSR1);
		wait( &status);
	}
}
