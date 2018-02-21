
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
  int nr, nw;
  FILE * fd1;
  FILE * fd2;
  unsigned char buffer[BUFFER_SIZE];

  if (argc !=  3)
  {
    printf("Usage: %s <source> <destination>\n",argv[0]);
    return 1;
  }

  //Abertura do source
  fd1= fopen(argv[1], "r");
  if(fd1 == NULL)
  {
    perror(argv[1]);
    return 2;
  }

  //Abertura do destination
  fd2= fopen(argv[2], "w");
  if(fd2==NULL)
  {
    perror(argv[2]);
    fclose(fd1);
    return 3;
  }

  //escreve enquanto ler algo para o buffer
  while((nr = fread(buffer,sizeof(char), BUFFER_SIZE, fd1))>0)
  {
    //Se der algum erro termina
    if((nw=fwrite(buffer, sizeof(char),nr,fd2))<= 0 || nw!= nr)
    {
      perror(argv[2]);
      fclose(fd2);
      fclose(fd1);
      return 4;
    }
  }
  fclose(fd2);
  fclose(fd1);
  return 0;
}
