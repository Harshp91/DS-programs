#include<iostream>
using namespace std;

int fac(int n)
{
    if(n==0)
     { return 1;}
    
    else{
     return n*fac(n-1);}
} 

int main()
{
    int a,i,f,n,j;
    cout<<"enter the value of n"<<endl;
    cin>>n;
    f=fac(n);
    cout<<f;

    return 0;
}