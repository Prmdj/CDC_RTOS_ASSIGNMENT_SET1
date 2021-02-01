#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<sys/ipc.h>


void main()
{
	key_t key; 
    key=ftok(".",'A');
    if(key==-1)
	 {
	 	perror("Key is not registered");
	 	//exit(0);
	 }
	 printf("%d",key);
}