#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int info;
    struct node *next;
};

struct node *getnode()
{
  struct node *p;
  p=(struct node*)malloc(sizeof(struct node));
  return p;
}

void insbeg(struct node **start ,int x)
{
    struct node *p;
    p=getnode();
    p->info=x;
    p->next=*start;
    *start=p;
}

void insend(struct node **start,int x)
{
  struct node *p,*q;
  q=*start;
  while(q->next!=NULL)
  {
    q=q->next;
  }
  p=getnode();
  p->info=x;
  p->next=NULL;
  q->next=p;
}

void traversing(struct node **start)
{
    struct node *p;
    p=*start;
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
    while(p!=NULL)
    {
        cout<<p->info<<endl;
        p=p->next;
    }
}

void insafter(struct node **q,int x)
{
    struct node *r,*p,*Z;
    p=getnode();
    p->info=x;
    r=(*q)->next; 
    p->next=r;
    (*q)->next=p; 
}

void insert(int n,int x)
{
    struct node *p,*r;
    struct node *start=NULL;
    int c1=0,c2=0,i,j,y;
    p=start;
    while(p!=NULL)
    {
        cout<<p->info<<endl;
        if((p->info)%2==0)
        {
          c1=c1+1;
        }
        else
        {
          c2=c2+1;
        }
        p=p->next;
    }
    y=c1+c2;
    if(n==1)
    {
        insbeg(&start,x);
    }

    else if(n==y+1)
    {
       insend(&start,x);
    }

    else if(n>1 && n<=y)
    {
       p=start;
       for(i=1;i<n-1;i++)
       {
         p=p->next;
       }
       insafter(&p,x);
    }
    else
    {
        cout<<"void insertion"<<endl;
    }
}

void delbeg(struct node **start ,int x)
{
  struct node *p;
  p=start;
  int x=p->info;
  start=p->next;
  return x;
}

void delend(struct node **start ,int x)
{
    struct node *p;
    p=*start;
    while(q->next!=NULL)
    {
      q=q->next;
    }
    
}

int main()
{
  struct node *start= NULL;
  struct node *p;
  insbeg(&start,100);
  insbeg(&start,200);
  insbeg(&start,300);
  insbeg(&start,400);
  insbeg(&start,500);
  insend(&start,10);
  insend(&start,20);
  insend(&start,30);
  p=start;
    for(int i=1;i<5;i++)
    {
        p=p->next;
    }
  insafter(&p,5);
  traversing(&start);
  return 0;
}