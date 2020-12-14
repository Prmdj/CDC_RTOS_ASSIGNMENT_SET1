#include<stdio.h>

void readArray(int arr[] , int size)
{
	int i=0;
	printf("\n Enter the elements\n");
	for(i=0;i<size;i++)
	{
		printf("Enter arr[%d]\n",i );
		scanf("%d",&arr[i]);
	}
}

int getSum(int arr[],int size)
{
	int i=0,sum=0;
	for(i=0;i<size;i++)
	{
		sum+=arr[i];
	}
	return sum;
}

int getProduct(int arr[],int size)
{
	int i=0,product=1;
	for(i=0;i<size;i++)
	{
		product*=arr[i];
	}
	return product;

}
float getavg(int arr[],int size)
{
	int i=0;
	float sum=0,avg=0;
	for(i=0;i<size;i++)
	{
		sum+=arr[i];
	}
	avg=sum/size;
	return avg;
}
int main()
{
	int arr[10];
	readArray(arr,10);
	printf("\n Sum is %d\n",getSum(arr,10));
	printf("\n Product is %d\n",getProduct(arr,10));
	printf("\n Average is %0.2f\n",getavg(arr,10));
	return 0;
}