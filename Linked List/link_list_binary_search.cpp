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

void binary_search(struct node **start,int x)
{
    struct node *p;
    struct node *q;
    struct node *r;
    p=(*start);
    q=(*start);
    r=(*start);
    int l,c=0;
    l=length(&(*start));
    if(l%2==0){
        l=(l/2)-1;
    }
    else
    {
        l=l/2;
    }
    int l1=l;
    static int s=s+l1+1;
    //cout<<s<<endl;
    //cout<<l<<endl;
    while(l--)
    {
        r=r->next;
    }
    if(r->info==x)
    {
        cout<<r->info<<" "<<"value is present "<<endl;
        exit;
    }
    else
    {
        if(r->next==NULL)
        {
            cout<<x<<"value is not present"<<endl;
        }
        else
        {
            q=r->next;
            r->next=NULL;
            if(x>=q->info)
            {
                s=s-l1/2;
                binary_search(&q,x);
            }
            else
            {
                s=s+l1/2;
                binary_search(&p,x);
            }
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
  insend(&start,60);
  insend(&start,80);
  insend(&start,90);
  insend(&start,120);
  insend(&start,130);
  insend(&start,150);
  traverse(&start);
  binary_search(&start,130);
  return 0;
}