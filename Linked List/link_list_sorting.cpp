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
  p->next=(*start);
  (*start)=p;
}

int length(struct node **start)
{
    struct node *p;
    p=(*start);
    int c=0;
    while(p->next!=NULL)
    {
        p=p->next;
        c=c+1;
    }
    return c;
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
  while(p!=NULL)
  {
    cout<<p->info<<endl;
    p=p->next;
  }
}

int delbeg(struct node **start)
{
    struct node *p;
    p = *start;
    (*start) = p->next;
    int x = p->info;
    free(p);
    return x;
}

int delend(struct node **start)
{
    struct node *p, *q;
    p = *start;
    q = NULL;
    while (p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    q->next = NULL;
    int x = p->info;
    free(p);
    return x;
}

// void deleten(struct node **start,int x)
// {
//   struct node *p;

// }
void deletenode(struct node **start,int x)
{
  struct node *p;
  struct node *q;
  struct node *r;
  q=(*start);
  p=(*start)->next;
  if(p->next==NULL)
  {
    q->next=NULL;
    free(p);
  }
  else
  {
   while(p->next!=NULL)
   {
     if(q->info==x)
     {
       //cout<<"*"<<endl;
       free(q);
       q=p;
       p=p->next;
       (*start)=q;
     } 
     else if(p->info==x)
     {
       //cout<<"*"<<endl;
       if(p->next==NULL)
       {
         q->next = NULL;
         int x = p->info;
         free(p);
       }
       else
       {
         q->next=p->next;
         r=p->next;
         free(p);
         p=r;
       }
     }
     else
     {
       //cout<<"**"<<endl;
       q=p;
       p=p->next;
     }
   }
  }
}

void delaft(struct node **q)
{
    struct node *r;
    struct node *p;
    int x;
    r=(*q);
    p=(*q)->next;
    x=p->info;
    r->next=p->next;
    free(p);
    //return x;
    //traversing(&(*q));
}

void sorting(struct node **start)
{
    struct node *p;
    struct node *q;
    struct node *r;
    q=(*start);
    p=(*start)->next;
    while(q!=NULL)
    {
      p=q->next;
      while(p!=NULL)
      {
        if(q->info>p->info)
        {
          int x;
          x=q->info;
          q->info=p->info;
          p->info=x;
        }
        p=p->next;
      }
      q=q->next;
    }
    traverse(&(*start));
}

int main()
{
  struct node *start;
  start=NULL;
  insend(&start,10);
  insend(&start,40);
  insend(&start,50);
  insend(&start,50);
  insend(&start,20);
  insend(&start,60);
  insend(&start,50);
  insend(&start,30);
  traverse(&start);
  cout<<endl;
  sorting(&(start));
  //deletenode(&start,30);
  //traverse(&start);
}