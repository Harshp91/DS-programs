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
  cout<<p;
}


int delbeg(struct node **start)
{
    struct node *p;
    p = *start;
    *start = p->next;
    int x = p->info;
    free(p);
    cout<<x;
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
    cout<<x;
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
    /*
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
    */
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

void merge(struct node **start1,struct node **start2)
{
    struct node *p,*q,*r;
    struct node *start3;
    start3=NULL;
    p=*start1;
    q=*start2;
    while(p!=NULL && q!=NULL)
    {
        if(p->info < q->info)
        {
            insend(&start3,p->info);
            p=p->next;
        }
        else 
        {
            insend(&start3,p->info);
            q=q->next;
        }
    }

    while(p!=NULL)
    {
        insend(&start3,p->info);
        p=p->next;
    }
    while(q!=NULL)
    {
        insend(&start3,q->info);
        q=q->next;
    }
  
   r=start3;
   while(r!=NULL)
     {
         cout<<r->info<<endl;
         r=r->next;
     }
}
/*
void ordered insertion(struct node **start,int x)
{
  struct node *p ;
  struct node *q;
  q=NULL;
  while(p!=NULL && x>=p->next)
  {
    q=p;
    p=p->next;
  }
  if(q==NULL)
  {
     insbeg(&(*start),x);
  }
  else
  {
    insafter(&q,x);
  }
}
*/
int main()
{
  struct node *start1= NULL ,*start2= NULL;
  struct node *p,*q;
  insbeg(&start1,80);
  insbeg(&start1,60);
  insbeg(&start1,40);
  insbeg(&start1,30);
  insend(&start1,10);
  insend(&start1,50);
  insend(&start1,30);
  traversing(&start1);
  
  return 0;
}