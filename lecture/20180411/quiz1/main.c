#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){

		pid_t pid;

		switch(pid=fork()){
				case -1: 
						perror("fork");
						exit(1);
                        break;

				case 0 :

						printf(" Parent Process - My PID:%d, My Parent's PID:%d, My Child's PID : %d",(int)getpid(),(int)getppid(),(int)pid);
						for(int i=6;i<=9;i++){
								for(int j=1;j<=9;j++){
										printf("%d x %d = %d\n",i,j,i*j);
								}     
							
						}
						break;

				default :

						printf(" Child Process - My PID:%d, My Parent's PID:%d, My Child's PID : %d",(int)getpid(),(int)getppid(),(int)pid);
                        for(int i=2;i<=5;i++){
								for(int j=1;j<=9;j++){
										printf("%d x %d = %d\n",i,j,i*j);
								}
						}      
                        break;
		}
             return 0;
}

