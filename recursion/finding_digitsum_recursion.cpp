#include<iostream>
using namespace std;

int digsum(int n,int s)
{
    if(n==0)
    {
        return s;
    }
    else
    {
        s=s+n%10;
        return digsum(n/10,s); 
    }
}

int main()
{
    int n;
    cout<<"enter the number"<<endl;
    cin>>n;
    int s=0;
    cout<<digsum(n,s)<<endl;
    // while(n!=0)
    // {
    //     s=s+n%10;
    //     n=n/10;
    // }
    // cout<<s<<endl;
}