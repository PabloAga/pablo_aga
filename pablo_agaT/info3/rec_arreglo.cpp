#include<iostream>


using namespace std;

int maximo(int a[], int tamano){
if (tamano==1)
return a[tamano -1];

else{
if(a[tamano]>maximo(a, tamano-1)
return a[tamano];
}
}
int main(){
int a[10]={1,5,8,4,3,7,8,2,9,6} , tam=10 ,b[10];

b=maximo(a,tam);

for (int i=0; i<=10; i++)
 {
cout << b[i] << ' '<<endl;
 }

return 0;

}
