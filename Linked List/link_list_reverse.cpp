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
    (*q)->next=((*q)->next)->next;
    free((*q)->next);
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
    // cout<<c1<<" "<<c2<<endl;
    // cout<<"total no. of the nodes is "<<c1+c2<<endl;
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

void reverse(struct node **start1)
{
    struct node *p;
    struct node *q;
    struct node *r;
    p=(*start1);
    // if(p->next==NULL)
    // {
    //     traversing(&(*start1));
    // }
    if((*start1)->next->next==NULL)
    {
        q=(*start1)->next;
        q->next=p;
        p->next=NULL;
        (*start1)=q;
        //traversing(&(*start1));
    }
    else
    {
      r=(*start1)->next->next;
      q=(*start1)->next;
      p->next=NULL;
      while(r->next!=NULL)
       { 
           q->next=p;
           p=q;
           q=r;
           r=r->next;
       }
       //p->next=NULL;
       q->next=p;
       r->next=q;
       (*start1)=r;
       //traversing(&(*start1));
    }
}

int main()
{
  struct node *start1= NULL,*start2= NULL;
  struct node *p,*q;
  insbeg(&start1,50);
  insbeg(&start1,40);
  insbeg(&start1,30);
  insbeg(&start1,20);
  insbeg(&start1,10);
  //insend(&start1,100);
  //insend(&start1,200);
  //insend(&start1,300);
  //insend(&start1,400);
  traversing(&start1);
  reverse(&start1);
  cout<<"after reverse"<<endl;
  traversing(&start1);
}