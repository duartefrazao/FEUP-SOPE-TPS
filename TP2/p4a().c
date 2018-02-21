#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_USER_LEN 10
#define MAX_GRADE_LEN 5

int main(int argc, char *argv[])
{
  int fd;
  char c;
  char userBuffer[MAX_USER_LEN +1];
  char gradeBuffer[MAX_GRADE_LEN +1];
  char * string;
  if(argc !=2)
  {
    printf("Usage: %s <destination>\n",argv[0]);
    return 1;
  }

  fd= open(argv[1], O_WRONLY);
  if(fd==-1)
  {
    perror(argv[1]);
    return 1;
  }
  int i = 0;
  int j = 0;

  printf("Welcome to the grade recorder!\n");
  printf("To exit enter a $\n");

  //Pre formatting of the file
  write(fd,"Name      ", MAX_USER_LEN);
  write(fd,"Grade \n",7 );


  while(c != '$')
  {
    //Name section
    printf("Name: ");
    fflush(stdout);
    while(c != '$' &&i < MAX_USER_LEN && read(STDIN_FILENO, &c,1) && c != '\n' )
    {
      fflush(stdout);
      userBuffer[i++]= c;
    }

    //Grade Section
    if(c!= '$'){ c= 0;printf("Grade: ");}
    fflush(stdout);
    while(c != '$' && j < MAX_GRADE_LEN && read(STDIN_FILENO, &c,1) && c != '\n')
    {
      fflush(stdout);
      gradeBuffer[j++]= c;
    }

    //Write to file + variable reset
    if(c!= '$'){
      c= 0;
      write(fd,userBuffer,i+1);
      while(MAX_USER_LEN- (i++) >0)
        write(fd," ", 1);
      write(fd,gradeBuffer,j+1);
      write(fd, "\n",1);
      i=0;
      j=0;
    }
  }

  close(fd);
  return 0;
}
