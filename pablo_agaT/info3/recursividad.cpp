#include<iostream>


using namespace std;

int factorial(int n){
if(n==1)
return 1;
return n*factorial(n-1);
}

int main(){

int n=0 , facto=0;

cout<<"ingrese el factorial que quiere calcular"<<endl;
cin>>n;
facto= factorial(n);
cout<<"el factorial del numero ingresado es :"<<facto<<endl;



return 0;
}
