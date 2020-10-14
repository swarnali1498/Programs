#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int powerN(int a,int n)
{
	if(n==0)
	return 1;
	if(n==1)
	return a;
	else
	{
		return a*powerN(a,n-1);
	}
}
int powerLogN(int a,int n)
{
	if(n==0)
	return 1;
	if(n==1)
	return a;
	else
	{
		if(n%2==0)
		return powerLogN(a*a,n/2);
		else
		return a*powerLogN(a*a,n/2);
	}
}
int main()
{
	int a,n;
	clock_t s,e; float time;
	printf("\nEnter number and exponent: ");
	scanf("%d%d",&a,&n);
	s=clock();
	long int p=powerN(a,n);
	printf("\nTime required is %f",time);
	e=clock();
	time=(float)(e-s)/CLOCKS_PER_SEC;
	s=clock();
	p=powerLogN(a,n);
	printf("\nTime required is %f",time);
	e=clock();
	time=(float)(e-s)/CLOCKS_PER_SEC;
}
