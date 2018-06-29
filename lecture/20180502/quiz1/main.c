#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PORTNUM 4793

int main(void){

		int buf[256];
		struct sockaddr_in sin,cli;
		int sd,ns,clientlen=sizeof(cli);

		if((sd=socket(AF_INET,SOCK_STREAM,0))==-1){
				perror("socket");
				exit(1);
		}

		memset((char *)&sin,'\0',sizeof(sin));

		sin.sin_family = AF_INET;
		sin.sin_port=htons(PORTNUM);
		sin.sin_addr.s_addr=inet_addr("0.0.0.0");

		if(bind(sd,(struct sockaddr *)&sin,sizeof(sin))){
				perror("bind");
				exit(1);
		}

		if(listen(sd,5)){
				perror("listen");
				exit(1);
		}

		printf("waiting client....\n");
		if((ns=accept(sd,(struct sockaddr *)&cli,&clientlen))==-1){
				perror("accept");
				exit(1);
		}

		int n1=rand()%10+1;
		int n2=rand()%10+1;
		int result=n1*n2;

        buf[0]=n1;
		buf[1]=n2;

        int length = sizeof(buf)/sizeof(buf[0]);

		printf("send %d x %d\n",n1,n2);
		if(send(ns,buf,length,0)==-1){
		
				perror("send");
				exit(1);
		}
		
		if(recv(ns,buf,sizeof(buf),0)==-1){
				perror("recv");
				exit(1);
		}

		printf("recv %d\n",buf[0]);

		if(buf[0]==result){
				buf[0]=1;     
		}else{
				buf[0]=0;
		}
            
		if(send(ns,buf,length,0)==-1){
				perror("send");
				exit(1);
		}

		printf("send result\n");


		close(ns);
		close(sd);
		
	    return 0;
}
