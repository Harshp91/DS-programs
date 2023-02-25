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

void insbeg(struct node **start,int x)
{
  struct node *p;
  p=getnode();
  p->info=x;
  p->next=NULL;
  (*start)=p;
}

void insend(struct node **start,int x)
{
  struct node *p;
  struct node *q;
  p=(*start);
  if(p==NULL)
  {
    insbeg(&(*start),x);
  }
  else{
  while(p->next!=NULL)
  {
    p=p->next;
  }
  q=getnode();
  q->info=x;
  q->next=NULL;
  p->next=q;
 }
}

void traverse(struct node **start)
{
  struct node *p;
  p=(*start);
  while(p->next!=NULL)
  {
    cout<<p->info<<endl;
    p=p->next;
  }
}

void pair_swap(struct node **start)
{
  struct node *p;
  struct node *q;
  //q=getnode();
  int a;
  p=(*start);
  
  while(p!=NULL && p->next!=NULL)
  {
      a=p->info;
      //cout<<a<<endl;
      p->info=(p->next)->info;
      (p->next)->info=a;
      //cout<<p->info<<"*"<<(p->next)->info<<endl;
      p=(p->next)->next;
  }
}

int main()
{
 struct node *start;
 start=NULL;
 insend(&start,10);
 insend(&start,20);
 insend(&start,30);
 insend(&start,40);
 insend(&start,50);
 insend(&start,60);
 traverse(&start);
 pair_swap(&start);
 cout<<endl<<endl;
 traverse(&start);
}