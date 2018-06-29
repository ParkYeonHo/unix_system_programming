#include <stdio.h>
#include <sys/time.h>

void rand();

int main(void){

		int i;
		struct timeval t1,t2;

		gettimeofday(&t1,NULL);

		for(i=0;i<9999999;i++){
				rand();
		}

		gettimeofday(&t2,NULL);

		printf("%f\n",t1.tv_sec+t1.tv_usec*0.000001);
		printf("%f\n",t2.tv_sec+t2.tv_usec*0.000001);
		printf("%f\n",(t2.tv_sec+t2.tv_usec*0.000001)-(t1.tv_sec + t1.tv_usec*0.000001));

		return 0;

}


