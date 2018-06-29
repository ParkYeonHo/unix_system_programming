#include <stdio.h>
#include <sys/time.h>

int main(){

int i,j;
struct timeval t1,t2;

  gettimeofday(&t1,NULL);


  for (int i = 1; i <= 999; i++)
    {
      for (int j = 1; j <= 999; j++)
	{
	  printf ("%d x %d = %d\n", i, j, i * j);
	  printf ("\n");
	}
    }
    gettimeofday(&t2,NULL);
     printf("%f\n",(t2.tv_sec+t2.tv_usec*0.000001)-(t1.tv_sec + t1.tv_usec*0.000001));


  return 0;
}
