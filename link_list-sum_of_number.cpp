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

void insbeg(struct node **start ,int x);

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

void insbeg(struct node **start ,int x)
{
    struct node *p;
    p=getnode();
    p->info=x;
    p->next=*start;
    *start=p;
}

void traversing(struct node **start)
{
    struct node *p;
    p=*start;
    int c1=0,c2=0,i,j;
    while(p!=NULL)
    {
        cout<<p->info;
        p=p->next;
    }
}

void reverse(struct node **start)
{
  struct node *start2;
  struct node *p;
  start2=NULL;
  p=*start;
  while(p!=NULL)
  {
    insbeg(&start2,p->info);
    p=p->next;
  }
  struct node *q;
  q=start2;
  p=*start;
  while(q!=NULL && p!=NULL)
  {
    p->info=q->info;
    p=p->next;
    q=q->next;
  }
}

void add(struct node **start1,struct node **start2)
{
    struct node *p;
    struct node *start3;
    struct node *q;
    start3=NULL;
    int sum,total,cary;
    reverse(&(*start1));
    reverse(&(*start2));
    p=*start1;
    q=*start2;
    while(p!=NULL && q!=NULL)
    {
        total=(p->info)+(q->info);
        sum=total%10;
        cary=total/10;
        p=p->next;
        q=q->next;
        insend(&start3,sum);
    }
    while(p!=NULL)
    {
        total=p->info+cary;
        sum=total%10;
        cary=total/10;
        p=p->next;
        insend(&start3,sum);
    }
    while(q!=NULL)
    {
        total=q->info+cary;
        sum=total%10;
        cary=total/10;
        q=q->next;
        insend(&start3,sum);
    }
    if(cary>0)
    {
        insend(&start3,cary);
    }
    cout<<"after reverse"<<endl;
    traversing(&(*start1));
    cout<<endl;
    traversing(&(*start2));
    cout<<endl<<"after addition"<<endl;
    traversing(&start3);
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

void orderinsert(struct node **start3,int x )
{
    struct node *p,*q;
    p=*start3;
    while(p!=NULL)
    {
        if(p->info==x)
        {
            insafter(&p,x);
            break;
        }
        else if(p->next==NULL)
        {
            insend(&p,x);
            break;
        }
        else if(p==NULL)
        {
            insbeg(&p,x);
            break;   
        }
        else 
        {
            p=p->next;
        }
    }
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

int main()
{
    struct node *start1= NULL;
    struct node *start2= NULL;
    struct node *p,*q;
    insend(&start1,5);
    insend(&start1,6);
    insend(&start1,7);
    traversing(&start1);
    cout<<endl;
    insend(&start2,8);
    insend(&start2,9);
    insend(&start2,6);
    p=start2;
    traversing(&start2);
    cout<<endl;
   // cout<<endl<<endl;
   // cout<<"after summation"<<endl;
   // addition(&start1,&start2);
   // cout<<endl<<endl;
   //
   // cout<<"after deletion"<<endl;
   // subs(&start1,&start2);
   // cout<<endl<<endl;
   // cout<<"after multiplication "<<endl;
   // multiply(&start1 , &start2);
   add(&start1,&start2);
   cout<<endl;
   //delaft(&p);
   //traversing(&start2);
   orderinsert(&start2,9);
   traversing(&start2);
  return 0;
}