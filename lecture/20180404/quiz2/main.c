#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int search();

int main(int argc,char *argv[]){

		search(argv[1]);
		return 0;
}
int search(char *p){
           
		DIR *dp;
        struct stat buf;
        struct dirent *dent;
		char path[BUFSIZ];

		if((dp=opendir(p))==NULL){
               perror("error!!");
			   exit(1);

         }

		while((dent=readdir(dp))){

				sprintf(path,"%s/%s",p,dent->d_name);
				stat(path,&buf);

				printf("%d ",(int)dent->d_ino);
				printf("%s\n",path);

				if(S_ISDIR(buf.st_mode)) {
				        if(strncmp(dent->d_name,".",1)==0){
                                continue;
						}
						search(path);
				}
	       	
		}
		
		 printf("\n\n");
         closedir(dp);

		return 0;
}
