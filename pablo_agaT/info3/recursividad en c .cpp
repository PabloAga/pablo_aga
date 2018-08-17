#include<iostream>


using namespace std;

int main(){

int n , facto;

cout<<"ingrese el factorial que quiere calcular"<<endl;
cin>>n;
facto= factorial(n);
count<<"el factorial del numero ingresado es :"<<facto<<endl;

}
int factorial(int n){
if(n==1)
return 1;
return n* factorial(n-1);
}

return 0;

