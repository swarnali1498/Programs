#include <iostream>
using namespace std;
#include<cstdlib>
class A
{
    int r,c,**m;
public:
    A(int x,int y):r(x),c(y)
    {
        cout<<"Constructor invoked"<<endl;
        m=new int*[r];
        for(int k=0;k<r;k++)
            m[k]=new int[c];
    }
    A(const A &ob)
    {
        cout<<"Copy constructor invoked"<<endl;
        r=ob.r;
        c=ob.c;
        m=new int*[r];
        for(int k=0;k<r;k++)
            m[k]=new int[c];
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                m[i][j]=ob.m[i][j];
            }
        }
    }
    ~A()
    {
        cout<<"Destructor invoked"<<endl;
        for(int k=0;k<r;k++)
            delete[] m[k];
        delete[] m;
    }
    void input()
    {
        cout<<"Enter data : "<<endl;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cin>>m[i][j];
            }
        }
    }
    void display()
    {
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cout<<m[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    A add(A ob)
    {
        int i,j;
        A ob1(2,2);
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                ob1.m[i][j]=m[i][j]+ob.m[i][j];
            }
        }
        ob1.display();
    }
    void subtract(A ob)
    {
        int i,j;
        A ob1(2,2);
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                ob1.m[i][j]=m[i][j]-ob.m[i][j];
            }
        }
            //display();
            //ob.display();
            ob1.display();
    }
    void multiply(A ob)
    {
        int i,j,l;
        A ob1(2,2);
        if(r!=c)
            cout<<"Matrix multiplication not possible"<<endl;
        else
        {
           // cout<<"ABC"<<endl;
            for(int i=0;i<ob1.r;i++)
            {
                for(int j=0;j<ob1.c;j++)
                {
                    for(l=0;l<r;l++)
                    {
                        ob1.m[i][j]+=m[i][l]*ob.m[l][j];
                    }

                }
            }
            ob1.display();
        }
    }
};
int main()
{
    A ob(2,2),ob1(2,2);
    ob.input();
    ob1.input();
    ob.display();
    ob1.display();
    A ob2(ob);
    A ob3(ob1);
    A ob4(ob);
    A ob5(ob1);
    cout<<"Addition : "<<endl;
    ob.add(ob1);
    cout<<"Subtraction : "<<endl;
    ob2.subtract(ob3);
    cout<<"Multiplication : "<<endl;
    ob4.multiply(ob5);
    return 0;
}
