#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>	
#include <sys/wait.h>

int main()
{
  int wstatus=0;
  int pid =fork();
  if(pid>0)
  {
	waitpid(pid,&wstatus,0);
	printf(" friends!\n");
	
  }else{
	int pid2=fork();
	if(pid2>0){
		waitpid(pid2,&wstatus,0);		
		printf("my ");
	}
	else printf("Hello ");
  }
  return 0;
}
