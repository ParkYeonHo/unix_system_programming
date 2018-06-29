#include <stdlib.h>
#include <stdio.h>

void cleanup1(void){
		printf("clean up 1 is called.\n");
}

void cleanup2(void){
		printf("clean up 2 is called.\n");
}

int main(void){
		atexit(cleanup1);
		atexit(cleanup2);

		exit(0);
}

