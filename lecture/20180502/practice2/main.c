#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define PORTNUM 3489

int main(void){

		char buf[256];
		struct sockaddr_in sin,cli;
		int sd,clientlen=sizeof(cli);

	    if((sd=socket(AF_INET,SOCK_DGRAM,0))==-1){
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

		while(1){
				if((recvfrom(sd,buf,255,0,(struct sockaddr *)&cli,&clientlen))==-1){
						perror("recvfrom");
						exit(1);
				}

				printf("** From client : %s\n",buf);
				strcpy(buf,"hello client");
				if((sendto(sd,buf,strlen(buf)+1,0,(struct sockaddr *)&cli, sizeof(cli)))==-1){
						perror("sendto");
						exit(1);
				}
              }
		return 0;
}


