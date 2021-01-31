#include<stdio.h>
#include <stdlib.h>
#include<sys/types.h> 
#include<unistd.h>

int main(int argc, char const *argv[])
{
	int i=0,cnt=0,pid,vow,p[2],ret;
	char str[100];

	printf("Enter the string\n");
	gets(str);

	pid=fork();
	ret=pipe(p);

	if (ret==-1)
	{
		printf("Pipe not created.\n");
	}

	if (pid==-1)
		printf("Fork error. Child process not created");

	else if(pid==0){
		printf("This is child process\n");
		close(p[1]);
		write(p[0],&str,sizeof(str));
		i=0;
		while(str[i]!='\0'){
			if (str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U')
			{
				vow++;
			}
			i++;
		}

		printf("There are %d vowels in %s\n",vow,str );

	}
	
	if (pid>0)
	{
		while(str[i]!='\0'){
		cnt++;
		i++;
		}

		printf("Count is %d\n",cnt );
		close(p[0]);
		write(p[1],&str,sizeof(str));
		wait(10);
	}

	return 0;
}