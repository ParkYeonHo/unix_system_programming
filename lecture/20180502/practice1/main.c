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

		char buf[256];
		struct sockaddr_in sin,cli;
		int sd,ns,clientlen=sizeof(cli);

		if((sd=socket(AF_INET,SOCK_STREAM,0))==-1){
				perror("socket");
				exit(1);
		}

		memset((char *)&sin,'\0',sizeof(sin));

		sin.sin_family=AF_INET;
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

		if((ns=accept(sd,(struct sockaddr *)&cli,&clientlen))==-1){
				perror("accept");
				exit(1);
		}

		sprintf(buf,"your ip address is %s",inet_ntoa(cli.sin_addr));

		if(send(ns,buf,strlen(buf)+1,0)==-1){
				perror("send");
				exit(1);
		}

		close(ns);
		close(sd);
		
		return 0;
}

