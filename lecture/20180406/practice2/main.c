#include <stdio.h>
#include <sys/times.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>


#define CLK_TCK sysconf(_SC_CLK_TCK)

int main(void){

		int i;
		time_t t;
		struct tms mytms;
		clock_t t1,t2;

		if((t1=times(&mytms))==-1){
				perror("time 1");
				exit(1);
		}

		for(i=0;i<9999999;i++){
				time(&t);
		}

		if((t2=times(&mytms))==-1){
				perror("times 2");
				exit(1);
		}

		printf("Real time : %.1f sec/\n",(double)(t2-t1)/ _SC_CLK_TCK);
		printf("User time : %.1f sec/\n",(double)mytms.tms_utime / _SC_CLK_TCK);
        printf("System time : %.1f sec/\n",(double)mytms.tms_stime / _SC_CLK_TCK);

		return 0;
		}

