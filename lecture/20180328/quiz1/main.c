#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]){

		FILE *rfp;
	    FILE *newFile;
		int num,n;

		if((rfp=fopen(argv[1], "r"))==NULL){
				perror("error : ");
				exit(1);
		}

		if((newFile=fopen("four.txt","w"))==NULL){

				perror("new file error");
						exit(1);

		}
                  
		while((n=fscanf(rfp,"%d",&num))!=EOF && num%4==0){
					
                     fprintf(newFile,"%d\n",num);
		}

		fclose(newFile);
		fclose(rfp);

		return 0;
}
