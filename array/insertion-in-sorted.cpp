#include <iostream>
using namespace std;

int main()
{
  int i,n,p=-1,x,t,j,e;

  cout<<"enter the size of the array"<<endl;
  cin>>n;
  int a[n];
  cout<<"enter the array elements"<<endl;
  for(i=0;i<n;i++)
  {
    cin>>a[i];
  }
  cout<<"enter the value of element to be insert"<<endl;
  cin>>e;

  for(i=0;i<n;i++)
  {
    if(e < a[i])
    {
      p=i;
      break;
    }
  }
  
  if(p==-1)
  {
    a[n]=e;
  }
  else
  {
    for(i=n-1;i>=p;i--)
    {
      a[i+1]=a[i];
    }
  }
  a[p]=e;

  cout<<"new array is"<<endl;
  for(i=0;i<n+1;i++)
  {
    cout<<a[i]<<" ";
  }

 return 0;
}