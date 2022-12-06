#include<iostream>
using namespace std;
#include<string.h>

void ispalrec(char s[],int b,int e)
{
    if(b==e)
    {
        cout<<"yes";
    }

    else if(s[b]!=s[e])
    {
        cout<<"No";
        exit;
    }

    else if(e>b)
    {
          ispalrec(s,b+1,e-1);
    }
}

void ispal(char s[])
{
   int n=strlen(s);

   if(n==0)
   {
    cout<<"Yes";
   }

   else
   {
     return ispalrec(s,0,n-1);
   }
}

int main()
{
  char s[100];
   cout<<"enter the string"<<endl;
   cin>>s;
   ispal(s);
}