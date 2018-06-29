#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){

		int status;
		pid_t pid;

		switch(pid=fork()){

				case -1:
						perror("fork");
						exit(1);
						break;

				case 0: 
                
					printf("-->child process -My PID:%d\n",(int)getpid());
					if(execlp("./gugudan.out","",(char *)NULL)==-1){
							perror("execlp");
							exit(1);
					}

				default :
						wait(&status);
						printf("-->Parent process -My PID:%d\n",(int)getpid());
						break;
		}
		return 0;
}



