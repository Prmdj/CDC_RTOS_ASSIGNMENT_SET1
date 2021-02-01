#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

void main(int argv,char *args[])
{
	pid_t pid;
	int fd1[2];
	if(pipe(fd1)==-1)
	{
		perror("Pipe is not working");
		exit(0);
	}
	pid=fork();
	if(pid<0)
	{
		perror("fork not working");
		exit(0);
	}
	else
		if(pid>0)
		{
		   close(fd1[0]);
           char c[strlen(args[1])];
           strcpy(c,args[1]);
           char rc[strlen(args[1])];
           int i;
           for(i=0;i<strlen(c);i++)
           	c[i]=tolower(c[i]);
           for(i=0;i<strlen(c);i++)
           	rc[strlen(c)-1-i]=c[i];
           rc[i]='\0';
           if(strcmp(c,rc)==0)
           	write(fd1[1],&c,strlen(c));
           else
           {
           	strcpy(c,"npalin");
           	write(fd1[1],&c,strlen(c));
           }
 
		}
		else
			if(pid==0)
			{
				close(fd1[1]);
				char buff[strlen(args[1])];
				read(fd1[0],&buff,strlen(buff));
				if(strcmp(buff,"npalin")==0)
				{
					printf("Not a palindrome");
					exit(0);
				}
				int  vowels=0;
				for(int i=0;i<strlen(buff);i++)
				{
					switch(buff[i]){
						case 'a':
							vowels++;
							break;
						case 'e':
						    vowels++;
						    break;
						case 'i':
						    vowels++;
						    break;
						case 'o':
						    vowels++;
						    break;
						case 'u':
						     vowels++;
						     break;


					}
				}
				printf("\nNumber of vowels in %s is %d",buff,vowels);
				
			}

}