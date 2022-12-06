#include<iostream>
#include<stdlib.h>
using namespace std;

void addition(struct node **poly1,struct node **poly2);

struct node
{
    char info;
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

void insbeg(struct node **start ,char x)
{
    struct node *p;
    p=getnode();
    p->info=x;
    p->next=*start;
    *start=p;
}

void insbegalp(struct node **start ,char x)
{
    struct node *p;
    struct node *r;
    struct node *q;
    struct node *m;
    p=(*start);
    char c;
    while(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
    {
      r=p;
      p=p->next;
      c=p->info;
    }
    q=getnode();
    q->info=x;
    r->next=q;
    q->next=p;
}

void insend(struct node **start,char x)
{
  struct node *p;
  struct node *q;
  q=(*start);
  if(q==NULL){
	  insbeg(&(*start),x);
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

void insaft(struct node **q,char x)
{
    struct node *r,*p,*Z;
    p=getnode();
    p->info=x;
    r=(*q)->next; 
    p->next=r;
    (*q)->next=p; 
}

void consonent(struct node **start)
{
  struct node *p;
  struct node *start1=NULL;
  struct node *r;
  p=(*start);
  char c;
  while(p!=NULL)
  {
    c=p->info;
    // if(start1==NULL)
    // {
    //   insbeg(&start1,c);
    //   cout<<c<<endl;
    //   p=p->next;
    // }
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
    {
      insbeg(&start1,c);
      r=start1;
      p=p->next;
    }
    else
    {
      insend(&start1,c);
      p=p->next;
    }
  }
  traverse(&start1);
}

int main()
{
  struct node *start= NULL;
  struct node *p;
  char s[100];
  int l,i=0;
  cout<<" enter the name "<<endl;
  cin>>s;
  while(s[i]!='\0')
  {
    insend(&start,s[i]);
    //cout<<s[i]<<endl;
    i=i+1;
  }
  traverse(&start);
  consonent(&start);
  return 0;
}