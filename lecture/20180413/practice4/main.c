#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
		printf("-->before exec fnction\n");

		if(execlp("ls","ls","-a",(char *)NULL)==-1){
				perror("execlp");
				exit(1);
		}

		printf("--> after exec function\n");

		return 0;
}

