#include <stdio.h>
#include <time.h>

int main ()
{
   time_t seconds;
/*
   seconds = time(NULL);
   printf("Hours since January 1, 1970 = %ld\n", seconds/3600);
 */

time_t rawtime;

  time (&rawtime);
  printf ("The current local time is: %s", ctime (&rawtime));

 
   return(0);
}
