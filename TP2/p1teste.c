#include <termios.h>
#include <unistd.h>
#include <string.h>

#define MAX_PW_LEN 20

int main(void){
	struct termios, term, oldterm;
	int i;

	char pass[MAX_PW_LEN+1]; //+1 for the null terminator
	char ch, echo='*';

	write(STDOUT_FILENO, "\nPassword? ",11 );

	//Change STDIN configurations
	tcgetattr(STDIN_FILENO, &oldterm);
	term = oldterm;
	term.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL | ICANON); //Disable echo flags
	tcsetattr(STDIN_FILE, TCSAFLUSH,&term ); //TCSAFLUSH discard input not read untill now

	i=0;
	while(i < MAX_PW_LEN && read(STDIN_FILENO, &ch,1) && ch != '\n')
	{
		pass[i++]=ch;
		write(STDOUT_FILENO,&echo,1);
	}
	pass[i]=0;

	tcsetattr(STDIN_FILENO, TCSANOW, &oldterm) //Change occurs immediately
	write(STDOUT_FILENO, "Password read: ", 15);
	write(STDOUT_FILENO, pass, strlen(pass));
	write(STDOUT_FILENO,"\n", 1);

	return 0;


}
