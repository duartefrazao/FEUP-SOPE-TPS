#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>	
#include <sys/wait.h>

int main()
{
  int wstatus=0;
  pid_t pid =fork();
  if(pid>0)
  {
	printf("Hello ");
  }else{
	printf(" world!\n");
  }
}
