#include <stdio.h>
#include <unistd.h>

int main(void) { 
 int i = 5; 
 while(i-->0) printf("\n");


 if(fork() > 0) { 
   printf("2"); 
   printf("3"); 
 } else { 
   printf("4"); 
   printf("5"); 
 } 
 printf("\n");
 
 return 0; 
} 
