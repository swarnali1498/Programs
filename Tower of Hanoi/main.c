#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void move(int n,char source,char dest,char spare)
{
	if(n==1)
	return;
	else
	{

		move(n-1,source,spare,dest);
		move(1,source,dest,spare);
		move(n-1,spare,dest,source);
	}
}
int main()
{
	int n;
	clock_t s,e; double time;
	printf("\nEnter limit: ");
	scanf("%d",&n);
	s=clock();
	move(n,'A','B','C');
	e=clock();
	time=((double)(e-s))/CLOCKS_PER_SEC;
	printf("Time taken by Tower of Hanoi is %lf",time);
}
