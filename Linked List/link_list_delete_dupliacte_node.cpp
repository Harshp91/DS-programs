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

void delaft(struct node **q)
{
    struct node *r,*p,*Z;
    r=*q;
    p=(*q)->next;
    r->next=p->next;
    free(p);
    //traversing(&(*q));
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
  if(q==NULL){
	insbeg(start,x);
  }
  else{
  while(q->next!=NULL)
  {
    q=q->next;
  }
  p=getnode();
  p->info=x;
  p->next=NULL; 
  q->next=p;
  }
}

void traverse(struct node **start)
{
    struct node *p;
    p=*start;
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

int length(struct node **start)
{
    struct node *p;
    p=(*start);
    int c=0;
    while(p!=NULL)
    {
        p=p->next;
        c=c+1;
    }
    return c;
}

void deletenode(struct node **start,int x)
{
    struct node *p;
    struct node *q;
    p=(*start);
    q=NULL;
    while(p->next!=NULL)
    {
      if(p->info==x)
      {
        if(q==NULL)
        {
            p=p->next;
            delbeg(&(*start));
        }
        else
        {
            p=p->next;
            delaft(&q);
        }
      }
      q=p;
      p=p->next;
    }
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
}

void duplicate(struct node **start)
{
    struct node *p;
    struct node *q;
    p=(*start);
    q=(*start);
    sorting(&(*start));
    while (p != NULL) {
        if (q == p) {
            cout << q->info << "\n";
        }
        p = p->next;
        if (p != NULL && p->info != q->info) {
            q = p;
        }
    }
}

int main()
{
  struct node *start= NULL;
  struct node *p,*q;
  insend(&start,10);
  insend(&start,20);
  insend(&start,30);
  insend(&start,30);
  insend(&start,40);
  insend(&start,50);
  insend(&start,30);
  insend(&start,50);
  traverse(&start);
  cout<<endl;
  duplicate(&start);
  //
  //traverse(&start);
  return 0;
}