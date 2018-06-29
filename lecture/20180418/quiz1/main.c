#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t m_lock;

void *t_func (void *data)
{
  int *count = (int *) data;
  pthread_t thread_id = pthread_self ();
  printf ("thread : %d     %d\n", *count, (int) thread_id);
  free(data);
}

int main (int argc, char *argv[])
{

  int i;
  int threadCount = atoi (argv[1]);
  pthread_t t_id;

  for (i = 0; i < threadCount; i++)
    {
	
    int *count =malloc(sizeof(int));
    	*count=i+1;
         pthread_create (&t_id, NULL, t_func, (void *)count);
    }
  pthread_join (t_id, NULL);

  return 0;
}
