#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
void push(char);
char pop();
void peep(char*,int);
int precedence(char);
void evaluate(char*);
char stack[100];
int top=-1;
int main()
{
    int i=0,j=0,d,k=0,m;
    char ch1,exp[100],str[10],post[100];
    printf("\nEnter infix expression : ");
    gets(exp);
    printf("\nInfix expression is : ");
    puts(exp);
    while(1)
    {
        if(isdigit(exp[i]))
            d=1;
        else
            d=0;
        j=0;
        while(exp[i]!=' ' && exp[i]!=NULL)
        {
            str[j++]=exp[i++];
        }
        if(exp[i]!=NULL)
        i++;
        if(d==1)
        {
            int p=0;
            while(p<j)
            post[k++]=str[p++];
            post[k++]=' ';
        }
        else
        {
            char ch=str[0];
            if(ch=='(')
            {
                push(ch);
            }
            else if(ch==')')
            {
                while(1)
                {
                    if(stack[top]=='(')
                        break;
                    ch1=pop();
                    post[k++]=ch1;
                    post[k++]=' ';
                }
                top--;
            }
            else if(ch=='^')
            {
                push(ch);
            }
            else
            {
                int p,q;
                p=precedence(ch);
                if(top>-1 && stack[top]!='(')
                {
                    q=precedence(stack[top]);
                    if((p-q)>0)
                    {
                        push(ch);
                    }
                    else
                    {
                        while((p-q)<=0)
                        {
                            ch1=pop();
                            post[k++]=ch1;
                            post[k++]=' ';
                            if(top==-1 || stack[top]=='(')
                                break;
                            q=precedence(stack[top]);
                        }
                        push(ch);
                    }
                }
                else
                {
                    push(ch);
                }
            }
        }
        if(exp[i]==NULL)
            break;
    }
    while(top>-1)
    {
        ch1=pop();
        post[k++]=ch1;
        post[k++]=' ';
    }
    peep(post,k);
    evaluate(post);
    return 0;
}
void push(char ch)
{
    stack[++top]=ch;
}
char pop()
{
    return stack[top--];
}
void peep(char* post,int k)
{
    int i;
    printf("\nPostfix expression is : ");
    for(i=0;i<k;i++)
    {
        printf("%c",post[i]);
    }
}
int precedence(char ch)
{
    int p;
    switch(ch)
    {
            case '^' : p=3;
                       break;
            case '%' : p=2;
                       break;
            case '/' : p=2;
                       break;
            case '*' : p=2;
                       break;
            case '+' : p=1;
                       break;
            case '-' : p=1;
                       break;
    }
    return p;
}
void evaluate(char* post)
{
    int ar[10],p=0,i=0,j=0,k=0,l=0;
    char ch,str[10];
    while(1)
    {
        if(isdigit(post[i]))
        {
            j=0; k=0; p=0;
            while(post[i]!=' ' && post[i]!=NULL)
            {
                str[j++]=post[i++];
            }
            if(post[i]!=NULL)
            i++;
            while(k<j)
            {
                p=p+((int)str[k]-48)*(pow(10,j-1-k));
                k++;
            }
            ar[l++]=p;
        }
        else
        {
            int c;
            p=0;
            j=ar[l-2];
            k=ar[l-1];
            ch=post[i++];
            i++;
            switch(ch)
            {
                case '^' : p=(int)pow(j,k);
                           break;
                case '%' : p=j%k;
                           break;
                case '/' : p=j/k;
                           break;
                case '*' : p=j*k;
                           break;
                case '+' : p=j+k;
                           break;
                case '-' : p=j-k;
                           break;
            }
            ar[l-2]=p;
            l--;
        }
        if(post[i]==NULL)
            break;
    }
    printf("\nEvaluated value is %d",ar[0]);
}
