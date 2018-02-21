//FOLHA 2 - p2b.c
//FILE COPY
//USAGE: copy source destination

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
 int fd1,fd2, nr, nw;
 unsigned char buffer[BUFFER_SIZE];

 //Usages
 if (argc != 2 && argc !=3) {
  printf("Usage: \n\t%s <source> <destination>\n or \t <source> <destination>\n ", argv[0]);
  return 1;
}

  //Source file
 fd1 = open(argv[1], O_RDONLY);
 if (fd1 == -1) {
  perror(argv[1]);
  return 2;
 }

 //Destination file, if any
 if(argc!=2)
 {
   fd2 = open(argv[2], O_APPEND| O_WRONLY);
   if (fd2 == -1) {
    perror(argv[2]);
    return 3;
  }
   dup2(fd2, 1);
 }


 while ((nr = read(fd1, buffer, BUFFER_SIZE)) > 0)

  if ((nw = write(STDOUT_FILENO, buffer, nr)) <= 0 || nw != nr) {
   perror(argv[1]);
   close(fd1);
   //Close second file
   if(argc!=2){dup2(STDOUT_FILENO,fd2);close(fd2);}

   return 4;
  }
  close(fd1);
  
  //Close second file
  if(argc!=2){dup2(STDOUT_FILENO,fd2);close(fd2);}
  return 0;
}
