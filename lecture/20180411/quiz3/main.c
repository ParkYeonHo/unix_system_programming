#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/time.h>


int
main (void)
{

 struct timeval t1,t2;

  int status1;
  int status2;

  pid_t pid1;
  pid_t pid2;
  int ary[100001];

  for (int i = 2; i <= 330; i++)
    {
      for (int j = i * i; j <= 100000; j = j + i)
	{
	  if (ary[j] == 0)
	    {
	      ary[j] = 1;
	    }
	}
    }

   gettimeofday(&t1,NULL);

  switch (pid1 = fork ())
    {
    case -1:
      perror ("fork");
      exit (1);
      break;


    case 0:
      for (int i1 = 1; i1 <= 249; i1++)
	{
	  if (ary[i1] == 0)
	    {
	      printf ("%d\n", i1);
	    }
	}

      break;

    default:


      for (int i2 = 250; i2<= 499; i2++)
	{
	  if (ary[i2] == 0)
	    {
	      printf ("%d\n", i2);
	    }
	}


	  switch(pid2=fork()){
             
              case 0:
					  for(int i3=500;i3<=749;i3++){
							  if(ary[i3]==0){
									  printf("%d\n",i3);
							  }
					  }
			  break;

				 default :
			       wait(&status2);

				   for(int i4=750;i4<=1000;i4++){
						   if(ary[i4]==0){
								   printf("%d\n",i4);
						   }
				   }
                   break;
	          }
      break;

    }


       gettimeofday(&t2,NULL);
	   printf("%f\n",(t2.tv_sec+t2.tv_usec*0.000001)-(t1.tv_sec + t1.tv_usec*0.000001));
 
		return 0;
}
