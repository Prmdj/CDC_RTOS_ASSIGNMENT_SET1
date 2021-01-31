#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 

int main(int argc, char const *argv[])
{
	int arr[100],pid,sum=0,prod=1,i,temp,cnt=0;
	int p[2],p1[2],ret,ret1;
	float avg=0;

	printf("Enter the numbers\n");
	while(1)
	{
		scanf("%d",&temp);
		if(temp==999)
			break;
		else{
			arr[i]=temp;
			i++;
			cnt++;
		}

	}

	ret=pipe(p);
	ret1=pipe(p1);
	if (ret==-1)
	{
		printf("Pipe error. Pipe not created");
	}
	if (ret1==-1)
	{
		printf("Pipe error. Pipe not created");
	}
	pid=fork();

	if(pid==-1)
		printf("Fork error. Child process not created\n");

	else if(pid==0){
		printf("This is child process\n");
		for(i=0;i<cnt;i++){
			sum+=arr[i];
			prod*=arr[i];
			
		}

		
		close(p[0]);
		close(p1[0]);
		write(p[1],&sum,sizeof(sum));
		write(p1[1],&prod,sizeof(prod));

	}

	else if(pid>0){

		wait(10);
		printf("This is parent process\n");
		close(p[1]);
		read(p[0],&sum,sizeof(sum));
		close(p1[1]);
		read(p1[0],&prod,sizeof(prod));
		avg=(float)sum/cnt;
		printf("Sum is %d\n",sum );
		printf("Product is %d\n",prod );
		printf("Average is %.2f\n",avg );



	}

	return 0;
}