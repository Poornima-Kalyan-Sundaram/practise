#include <stdio.h>
#include <time.h>

int main ()
{
   time_t seconds;

   seconds = 1219356033;//time(NULL);
   printf("Hours since January 1, 1970 = %ld\n", seconds);
  /*
time_t rawtime;

  time (&rawtime);
 */ printf ("The current local time is: %s", ctime (&seconds));

   return(0);
}
