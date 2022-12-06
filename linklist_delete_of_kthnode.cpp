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

// void delaft(struct node **q)
// {
//     struct node *r,*p,*Z;
//     (*q)->next=((*q)->next)->next;
//     free((*q)->next);
// }

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

void insafter(struct node **q,int x)
{
    struct node *r,*p,*Z;
    p=getnode();
    p->info=x;
    r=(*q)->next; 
    p->next=r;
    (*q)->next=p; 
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

void traversing(struct node **start)
{
    struct node *p;
    p=*start;
    int c1=0,c2=0,i,j;
    while(p!=NULL)
    {
        cout<<p->info<<endl;
        p=p->next;
    }
}

void deleteknode(struct node **start, int k)
{
  struct node *p;
  struct node *q;
  p=(*start);
  q=(*start);
  int i=0,x;
  while(i<k)
  {
    i=i+1;
    p=p->next;
  }
  while(p->next!=NULL)
  {
    p=p->next;
    q=q->next;
  }
  delaft(&q);
  //cout<<x<<endl;
  traversing(&(*start));
}

int main()
{
  struct node *start=NULL;
  struct node *p;

  insbeg(&start,10);
  insbeg(&start,20);
  insbeg(&start,30);
  insbeg(&start,40);
  insend(&start,100);
  insend(&start,110);
  insend(&start,120);
  insend(&start,130);
  traversing(&start);
  //int i=0;
  //  p=start;
  //while(i<=3)
  //{
  //  p=p->next;
  //  //cout<<p->info<<endl;
  //  i++;
  //}
  //cout<<endl<<endl;
  //delaft(&p);
  //traversing(&start);
  cout<<endl;
  int n;
  cout<<"enter the value of kth node"<<endl;
  cin>>n;
  deleteknode(&start,n);
  return 0;
}