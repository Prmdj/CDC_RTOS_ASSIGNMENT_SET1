#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>

void main()

{
	
	key_t key; 
    key=ftok(".",'A');
    if(key==-1)
	 {
	 	perror("Key is not registered");
	 	exit(0);
	 }
	int *num;	
	int shmid;
	if((shmid=shmget(key,1024,IPC_CREAT | 0644))==-1)
	{
		perror("Didn't get the id");
		exit(0);
	}
    num=shmat(shmid,NULL,0);
    *num=999;
    while(*num==999);
    printf("\n%d\n",*num);
    *num=(*num)*(*num);
    shmdt(num);

}


