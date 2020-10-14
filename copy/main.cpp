#include<iostream>
using namespace std;
class complex{
int *real,*imag;
public:
complex(){
    cout<<"default constructor"<<endl;
real=new int; imag=new int;
*real=0; *imag=0;
}
complex(int a, int b){
    cout<<"constructor"<<endl;
real=new int; imag=new int;
*real=a; *imag=b;
}
complex(const complex & ob){
cout<<"copy"<<endl;
real=new int; imag=new int;
*real=*ob.real; *imag=*ob.imag;
}
complex add(complex obj){
*real=*real+*obj.real;
*imag=*imag+*obj.imag;
cout<<*real<<" " <<*imag<<endl;
return *this;
}
complex multiply(complex obj){complex c;
*c.real=*real-*obj.real;
*c.imag=*imag-*obj.imag;
cout<<*c.real<<" " <<*c.imag<<endl;
return c;
}
void show(){
cout<<*real<<" " <<*imag<<endl;
}
~complex(){cout<<"destructor"<<endl; cout<<"In destructor "<<*real<<" " <<*imag<<endl; delete real; delete imag;}

};
int main(){
complex a(1,2);
complex b(2,3);

complex result(a.add(b));
result.show();
complex result1=a.multiply(b);
result1.show();
return 0;
}
