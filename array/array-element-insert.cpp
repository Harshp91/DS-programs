
// insertiion  //

#include <iostream>
 using namespace std;

 int main()
{
  int i,n,p,x,e;

  cout<<"enter the size of the array"<<endl;
  cin>>n;
  int a[n];
  cout<<"enter the array elements"<<endl;
  for(i=0;i<n;i++)
  {
    cin>>a[i];
  }

  cout<<"enter the position of insertion of element in the array"<<endl;
  cin>>p;
  cout<<"enter the value of element to be insert"<<endl;
  cin>>e;
   for(i=n-1;i>=(p-1);i--)
   {
     a[i+1]=a[i];
   }

  a[p-1]=e;

  cout<<"new array is"<<endl;
  for(i=0;i<n+1;i++)
  {
    cout<<a[i]<<" ";
  }

  return 0;
}