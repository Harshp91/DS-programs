#include<iostream>
#include<stdlib.h>
using namespace std;

void insend(int x);
void insert(int n,int x);
void insafter(struct node *p,int x);

struct node{
    int info;
    struct node *next;
};

struct node *start;

struct node *getnode()
{
  struct node *p;
  p=(struct node*)malloc(sizeof(struct node));
  return p;
}

void insbeg(int x)
{
    struct node *p;
    p=getnode();
    p->info=x;
    p->next=start;
    start=p;
}


void insend(int x)
{
  struct node *p,*q;
  q=start;
  while(q->next!=NULL)
  {
    q=q->next;
  }
  p=getnode();
  p->info=x;
  p->next=NULL;  
  q->next=p;
}

void traversing()
{
    struct node *p;
    p=start;
    int c1=0,c2=0,i,j;
    while(p!=NULL)
    {
        cout<<p->info<<endl;
        if((p->info)%2==0)
        {
          c1=c1+1;
        }
        else{
          c2=c2+1;
        }
        p=p->next;
    }
    cout<<c1<<" "<<c2<<endl;
    cout<<"total no. of the nodes is "<<c1+c2<<endl;
    /*
    for(i=0;i<c1+c2;i++)
    {
      for(p=0;p<(c1+c2-i);p++)
      {
        if(p->info<(p+1)->info)
        {
            swap(p->info,(p+1)->info);
        }
      }
    }
    cout<<"afer sort "<<endl;
    while(p!=NULL)
    {
        cout<<p->info<<endl;
        p=p->next;
    }
    */
}

int main()
{
  start= NULL;
  insbeg(100);
  insbeg(200);
  insbeg(300);
  insbeg(400);
  insbeg(500);
  insend(10);
  insend(20);
  insend(30);
  traversing();
  return 0;
}