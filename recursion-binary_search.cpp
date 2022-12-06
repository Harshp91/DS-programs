#include <iostream>
#include<math.h>
using namespace std;

int binary(int a[],int low,int high,int key)
{
 if(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]==key)
        {
            return mid+1;
        }

        else
        {
             if(key<a[mid])
             {
                return binary(a,low,mid-1,key);
             }
             else
             {
               return binary(a,mid+1,high,key);
             }
        }

    }

  else
  {
    return -1;
  }
 }

int main()
{
    int i,j,key,mid,n;
    cout<<"enter the size of the array"<<endl;
    cin>>n;
    int a[n];
    cout<<"enter the array elements"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"enter the element to search"<<endl;
    cin>>key;
    int low=0, high=n-1;
    cout<<"element is found at position"<<" "<<binary(a,low,high,key)<<endl;
    
 return 0;
}