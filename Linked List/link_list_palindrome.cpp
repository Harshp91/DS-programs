#include<iostream>
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
  if((*start)!=NULL)
  {
    p->next=(*start);
    (*start)=p;
  }
  else
  {
    p->next=NULL;
    (*start)=p;
  }
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

void delend(struct node **start)
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
    //return x;
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

struct node *reverse(struct node **start)
{
    struct node *p;
    struct node *q;
    struct node *start1;
    start1=NULL;
    p=(*start);
    q=(*start);
    int l,x;
    l=length(&(*start));
    //cout<<l<<endl;
    l=l;
    while(l--)
    {
     x=q->info;
     //cout<<q->info<<endl;
     //cout<<x<<endl;
     insbeg(&start1,x);
     //cout<<x<<endl;
     q=q->next;
    }
    return start1;
}

void pallindrome(struct node **start)
{
    struct node *p;
    struct node *q;
    p=(*start);
    q=reverse(&(*start));
    int f=0;
    while(q!=NULL && p!=NULL)
    {
        if(q->info!=p->info)
        {
            f=1;
            break;
        }
        else
        {
            p=p->next;
            q=q->next;
        }
    }
    if(f==0)
    {
        cout<<"Yes It is Pallindrome"<<endl;
    }
    else
    {
        cout<<"No It is not a Pallindrome"<<endl;
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
 insend(&start,30);
 insend(&start,20);
 insend(&start,10);
 traverse(&start);
 pallindrome(&start);
 
}