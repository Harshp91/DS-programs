#include<iostream>
using namespace std;
#include<string.h>

void revstr(char s[],int b,int e)
{
    if(b==e || b>e)
    {
        int i;
        cout<<s<<endl;
         exit;
    }

    else if(b<e)
    {
       int t=s[b];
       s[b]=s[e];
       s[e]=t;
       revstr(s,b+1,e-1);
    }
}

void rev(char s[])
{
   int n=strlen(s);

   if(n==1)
   {
    cout<<s;
   }

   else
   {
     return revstr(s,0,n-1);
   }
}


int main()
{
  char s[100];
   cout<<"enter the string"<<endl;
   cin>>s;
   rev(s);
}