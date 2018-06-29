#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>


int main(){

		struct timeval t1,t2;
		int ary[100001];

		for(int i=2;i<=303;i++){
				for(int j=i*i;j<=100000;j=j+i){
						if(ary[j]==0){
								ary[j]=1;
						}
				}

		}

		 gettimeofday(&t1,NULL);

		for(int i=1;i<=100000;i++){
				if(ary[i]==0){
						printf("%d\n",i);
		}


		gettimeofday(&t2,NULL);

		}
		printf("%f\n",(t2.tv_sec+t2.tv_usec*0.000001)-(t1.tv_sec + t1.tv_usec*0.000001));
		

		return 0;
}
    
