#include <stdlib.h>
#include <stdio.h>

int main(void){

		int a;
		a=system("ps -ef | grep bash > result.txt");
		printf("Return values : %d\n",a);

		return 0;
}

