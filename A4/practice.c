//sem_t *s1;
//sem_t *s2;
#include <stdio.h>
void  main(void)
{
     /*pid_t  pid;
     int    i;
     char   buf[BUF_SIZE];
     
     //s1 = sem_open( "first", O_CREAT, 0666, 1 );
     //s2 = sem_open( "second", O_CREAT, 0666, 0 );

     int x = fork();
     pid = getpid();
     for (i = 1; i <= MAX_COUNT; i++) {
     
          if( x == 0 ){
            sem_wait( s1);
          }
          else{
            sem_wait( s2 );
          }
          
          sprintf(buf, "This line is from pid %d, value = %d\n", pid, i);
          write(1, buf, strlen(buf));
          
          if( x == 0 ){
            sem_post( s2);
          }
          else{
            sem_post( s1 );
          }
     } */
     char first_letter = 'a';
     int i = (int)first_letter - (int)'a';
     printf("%d \n", i);
}
