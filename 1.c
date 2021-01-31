#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 

int main(int argc, char const *argv[])
{
	int arr[10],pid,sum=0,avg=0,prod=1,i,p[2],ret;

	printf("Enter 10 elements:\n");

	for (int i = 0; i < 10; ++i)
	{
		scanf("%d",&arr[i]);
	}

	ret=pipe(p);
	if (ret==-1)
	{
		printf("Pipe error. Pipe not created");
	}
	pid=fork();

	if(pid==-1)
		printf("Fork error. Child process not created\n");

	else if(pid==0){
		printf("This is child process\n");
		for(i=0;i<10;i++){
			sum+=arr[i];
			prod*=arr[i];
			
		}

		printf("Sum is %d\n",sum );
		printf("Product is %d\n",prod );
		close(p[0]);
		write(p[1],&sum,sizeof(sum));

	}

	else if(pid>0){

		wait(10);
		printf("This is parent process\n");
		close(p[1]);
		read(p[0],&sum,sizeof(sum));
		avg=sum/10;
		printf("Average is %d\n",avg );


	}

	return 0;
}