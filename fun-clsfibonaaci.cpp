#include <iostream>
using namespace std;

int fib(int n)
{
    if(n==1)
    {
      return fib(n)=0;
    }

    else if(n==2)
    {
      return fib(n)=1;
    }

    else
    {
        return fib(n)=fib(n-1)+fib(n-2);
    }

}

int main()
{
    int n;
    cout<<"enter the term upto which fibnacci series is to find";
    cin>>n;
    int a=0 , b=1;
    cout<<fib(n)<<" ";
   
  return 0;
}
