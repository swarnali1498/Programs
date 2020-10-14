#include<iostream>
using namespace std;
class complex{
int *real,*imag;
public:
complex(){
real=new int; imag=new int;
*real=0; *imag=0;
}
complex(int a, int b){
real=new int; imag=new int;
*real=a; *imag=b;
}
complex(const complex& obj)
{
    cout<<"copy"<<endl;
    real=new int;
    imag=new int;
    *real=*obj.real;
    *imag=*obj.imag;
}
complex add(complex obj){ complex c;
*c.real=*real+*obj.real;
*c.imag=*imag+*obj.imag;
return c;
}
void show(){
cout<<*real<<" " <<*imag<<endl;
}
~complex(){cout<<"destructor "<<*real<<" "<<*imag<<endl;delete real; delete imag;}

};

int main(){
complex a(1,2);
complex b(2,3);
complex result=a.add(b);
result.show();
return 0;
}
