#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *threadfunc(void *vargp);

void *threadfunc(void *vargp){
		sleep(1);
		printf("Hello world\n");
		return NULL;
}


int main(){
		pthread_t tid;

		pthread_create(&tid,NULL,threadfunc,NULL);
		printf("main\n");
		pthread_join(tid,NULL);
		printf("main2\n");
		sleep(2);
		return 0;
}
