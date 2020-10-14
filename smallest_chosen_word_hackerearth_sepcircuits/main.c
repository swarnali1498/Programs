#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int randomized_partition(char* A, long int p, long int r)
{
  //  printf("%s",A);
	long int i=p-1,j;
	char t;
	for(j=p;j<=r-1;j++)
	{
		if((int)A[j]<(int)A[r])
		{
		    i++;
			t=A[i];
			A[i]=A[j];
			A[j]=t;
		}
	}
	t=A[i+1];
	A[i+1]=A[r];
	A[r]=t;
	printf("%c",A[r]);
	return (i+1);
}
void quicksort(char* A, long int p, long int r)
{
	if(p<r)
	{
		long int q=randomized_partition(A,p,r);
		quicksort(A,p,q-1);
		quicksort(A,q+1,r);
	}
}
void main()
{
    long int l1,l2,l3,i,j,k=0;
    printf("\nEnter size of three strings: ");
    scanf("%ld%ld%ld",&l1,&l2,&l3);
    if(l1<=100000 && l2<=100000 && l3<=100000)
    {
        char s1[l1],s2[l2],s3[l3],p[l2];
        printf("\nEnter strings: ");
        scanf("%s %s %s",s1,s2,s3);
        for(i=0;i<l2;i++)
        {
            if((int)s2[i]<(int)s3[0])
            {
                p[k++]=s2[i];
            }
        }
        p[k]=NULL;
        quicksort(p,0,k);
        printf("%s\n",p);
     /*   for(i=0;i<k;i++)
        {
            for(j=0;j<k-1-i;j++)
            {
                if((int)p[j]>(int)p[j+1])
                {
                    printf(" (%d %d) ",(int)p[j],(int)p[j+1]);
                    char t;
                    t=p[j];
                    //printf("%c ",t);
                    p[j]=p[j+1];
                    p[j+1]=t;
                }
            }
        }*/
        printf("%s",strcat(s1,strcat(p,s3)));
    }
}
