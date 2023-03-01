#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int info;
    struct node *next;
    struct node *prev;
};

struct node *getnode()
{
  struct node *p;
  p=(struct node*)malloc(sizeof(struct node));
}


int delbeg(struct node **start)
{
    struct node *p;
    p = *start;
    *start = p->next;
    //int x = p->info;
    free(p);
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
    //int x = p->info;
    free(p);
}

int delaft(struct node **start,int n)
{
    struct node *p;
    p = *start;
    while (p->info != n)
        p = p->next;
    struct node *q, *r;
    q = p->next;
    r = q->next;
    p->next = r;
    int x = q->info;
    free(q);
    cout<<x;
}

void insbeg(struct node **dstart ,int x)
{
    struct node *p;
    p=getnode();
    p->info=x;
    p->prev=NULL;
    if((*dstart)!=NULL)
    {
      (*dstart)->prev=p;
    }
    p->next=(*dstart);
    (*dstart)=p;
}

void insend(struct node **dstart,int x)
{
  struct node *p,*q;
  p=(*dstart);
  q=getnode();
  q->info=x;
  q->next=NULL;
  if((*dstart)!=NULL)
  {
     while(p->next!=NULL)
     {
       p=p->next;
     }
     p->next=q;
     q->prev=p;
  }
  else
  {
    q->prev=NULL;
    (*dstart)=q;
  }
}

void insafter(struct node **p,int x)
{
    struct node *r;
    struct node *q;
    q=getnode();
    q->info=x;
    r=(*p)->next;
    (*p)->next=q;
    q->prev=(*p);
    q->next=r;
    if(r!=NULL)
    {
      r->prev=q;
    }
}

void insbef(struct node **p,int x)
{
  struct node *r;
    struct node *q;
    q=getnode();
    q->info=x;
    r=(*p)->prev;
    (*p)->prev=q;
    q->prev=r;
    q->next=(*p);
    if(r!=NULL)
    {
      r->next=q;
    }
}

void traverse(struct node **dstart)
{
    struct node *p;
    p=(*dstart);
    while(p!=NULL)
    {
        cout<<p->info<<endl;
        p=p->next;
    }
}
int main()
{
  struct node *dstart= NULL ;
  struct node *p;
  struct node *q;
  insbeg(&dstart,80);
  insbeg(&dstart,60);
  insbeg(&dstart,40);
  insbeg(&dstart,30);
  insend(&dstart,10);
  insend(&dstart,50);
  insend(&dstart,30);
  traverse(&dstart);

  //p=dstart;
  //while((p->next)->next!=NULL)
  //{
  //  p=p->next;
  //}
  //q=p;
  //insafter(&p,100);
  //insbef(&q,200);
  //delend(&dstart);
  //delbeg(&dstart);
  //traverse(&dstart);
  
  return 0;
}