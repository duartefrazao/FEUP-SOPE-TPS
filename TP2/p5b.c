// PROGRAMA p5b.c

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(void)
{
  int fd;
  char *text1="CCCCC";
  char *text2="DDDDD";

  fd = open("f1.txt", O_WRONLY|O_SYNC,0600);
  if(fd == -1)
  {
    perror("f1.txt");
    return 1;
  }

  printf("Type something: ");
  getchar();
  if(write(fd,text1,5)<=0)
  {
    perror("f1.txt");
    return 2;
  }
  
  printf("Type something: ");
  getchar();
  if(write(fd,text2,5)<=0)
  {
    perror("f1.txt");
    return 3;
  }
  close(fd);
  return 0;
}
