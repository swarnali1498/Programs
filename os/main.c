#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int isPrime(int n) {
	int flag, i;
	for(i=2;i<n;i++) 	{
	   if(n%i==0)
	   {    flag=0;  break;    }
	   flag=1;
	}
	return flag;
}
void range(int low,int high, char *msg) {
	int j;
	for(j=low; j<=high;j++) 	{
		if(isPrime(j))
		  printf("%s prime -> %d \n",msg,j);
	}
}
int main() {
	int pid1,pid2,pid3;
	int p1[2], p2[2], p3[2];
	char str1[30],str2[30],str3[30];
	int start,end,mid1,mid2;
        char buf1[30], buf2[30], buf3[30];
	char *mg1="child 1", *mg2="child2", *mg="child3";
	pipe(p1);
	pid1=fork();
	if (pid1==0)
	{  printf("CHILD1: my pid = %d, my parent-ID = %d \n",getpid(),getppid());
           read(p1[0],buf1,sizeof(buf1));
	   sscanf(buf1,"%d%d",&start,&end);
	   range(start,end,mg1); sleep(2);
	}
	else if (pid1>0) 	{
                        printf("PARENT: my pid = %d and my child1 = %d \n",getpid(),pid1);
                       pipe(p2);
	        pid2=fork();
	        if (pid2==0)
                      {   printf("CHILD2: my pid = %d, my parent-ID = %d \n",getpid(),getppid());
                           sleep(2);
                           read(p2[0],buf2,sizeof(buf2));
                           sscanf(buf2,"%d%d",&start,&end);
                           range(start,end,mg2);
            }
	    else if (pid2>0)  {
                          printf("PARENT: my pid = %d and my child2 = %d \n",getpid(),pid2);
                           pipe(p3);
                           pid3=fork();
                           if (pid3==0)
                           {  printf("CHILD3: my pid = %d, my parent-ID = %d \n",getpid(),getppid());
                               sleep(4);
                              read(p3[0],buf3,sizeof(buf3));
 		  sscanf(buf3,"%d%d",&start,&end);
                	  range(start,end,mg);
                         }
	           else if (pid3>0)   {
                        //main program......................................................
                        printf("PARENT: my pid = %d and my child3 = %d \n",getpid(),pid3); sleep(2);

		 printf("enter range low high :");
		 scanf("%d %d",&start,&end);
		 mid1=(start+end)/3;
		 mid2=2*mid1;
                             printf("start = %d, mid1 = %d\n",start,mid1);
		 printf("mid1+1 = %d, mid2 = %d\n",(mid1+1),mid2);
                              printf("mid2+1 = %d, end = %d\n",(mid2+1),end);
		 sprintf(str1,"%d %d",start,mid1);
		 sprintf(str2,"%d %d",mid1+1,mid2);
		 sprintf(str3,"%d %d",mid2+1,end);
		 write(p1[1],str1,strlen(str1)+1); sleep(2);
		 write(p2[1],str2,strlen(str2)+1); sleep(2);
		 write(p3[1],str3,strlen(str3)+1); sleep(2);
		 wait();wait();wait();	// parent waits for three children.... You can comment out....
	       }
	       else printf("error fork3\n");
	    }
	    else  printf("error fork2\n");
	 }
	 else printf("error fork1\n");
     return 0;
}
