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

void insbeg(struct node **cstart ,int x)
{
    struct node *p;
    p=getnode();
    if((*cstart)!=NULL)
    {
        p->next=(*cstart)->next;
        (*cstart)->next=p;
        p->info=x;
    }
    else
    {
      *cstart=p;  
      (*cstart)->next=p;
       p->info=x;
    }
}

void traversal(struct node **cstart)
{
    struct node *p;
    p=(*cstart)->next;
    while(p!=(*cstart))
    {
        cout<<p->info<<endl;;
        p=p->next;
    }
    cout<<p->info<<" ";
}

void concat(struct node **cstart1,struct node **cstart2)
{
    struct node *p,*q,r;
    p=(*cstart1)->next;
    q=(*cstart2)->next;
    (*cstart1)->next=q;
    (*cstart2)->next=p;
    traversal(&(*cstart2));
}

void pattern(struct node **cstart1)
{
    struct node *p;
    p=(*cstart1);
    int s=0;
    while(p->next!=(*cstart1))
    {
      s=s+p->info;
      p=p->next;
    }
    s=s+p->info;
    p=(*cstart1);
    int s1;
    while(p->next!=(*cstart1))
    {
        s1=s;
        p->info=s1-p->info;
        p=p->next;
    }
    p->info=s1-p->info;
    traversal(&(*cstart1));
}

void fib(struct node **cstart)
{
  struct node *p;
  struct node *q;
  p=(*cstart);
  while(p!=(*cstart))
  {
    if(dat[p->info]==1)
    {
        q=p->next;
        delaft(q);
    }
    else
    {
        q=p;
        p=p->next;
    }
  }
  if(dat[p->info]==1)
  {
    delsft(q);
    (*cstart)=q;
  }
}

int main()
{
  struct node *cstart1= NULL;
  struct node *cstart2= NULL;
  struct node *p;
  struct node *q;
  insbeg(&cstart1,50);
  insbeg(&cstart1,40);
  insbeg(&cstart1,30);
  insbeg(&cstart1,70);
  insbeg(&cstart1,90);
  traversal(&cstart1);
  cout<<endl;
  insbeg(&cstart2,20);
  insbeg(&cstart2,10);
  insbeg(&cstart2,60);
  traversal(&cstart2);
 // cout<<endl;
 // cout<<endl;
 // concat(&cstart1,&cstart2);
  cout<<endl;
  cout<<endl;
  pattern(&cstart1);
  return 0;
}