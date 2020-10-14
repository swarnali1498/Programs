#include<stdio.h>
#include<stdlib.h>
#include<time.h>
long int powerN(int a,int n)
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
long int powerLogN(int a,int n)
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
    long long int p;
	printf("\nEnter number and exponent: ");
	scanf("%d%d",&a,&n);
	s=clock();
    p=powerN(a,n);
	e=clock();
	time=(float)(e-s)/CLOCKS_PER_SEC;
	printf("\nTime required is %f",time);
	s=clock();
	p=powerLogN(a,n);
    e=clock();
    time=(float)(e-s)/CLOCKS_PER_SEC;
    printf("\nTime required is %f",time);
    return 0;
}
