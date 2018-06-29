#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){

		pid_t pid;

		switch(pid=fork()){

				case -1:
						perror("fork");
						exit(1);
						break;

				case 0:
						printf("cild Process - My PID : %d, my Parent's PID : %d\n",(int)getpid(),(int)getppid());
						break;

				default:
						printf("Parent process - My PID : %d, My Parent's PID : %d,My Child's PID : %d\n",(int)getpid(),(int)getppid(),(int)pid);
						break;

		}

		printf("end\n");
		
		return 0;
}
