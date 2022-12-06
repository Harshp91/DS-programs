
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
    cout<<c1<<" "<<c2<<endl;
    cout<<"total no. of the nodes is "<<c1+c2<<endl;
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

void circular(struct node **start)
{
  struct node *t,*r,*m;
  t=*start;
  r=*start;
  r=r->next;
  while(r!=NULL && r->next!=NULL)
  {
    t=t->next;
    r=r->next;
    r=r->next;
    if(t==r)
    {
      cout<<"true";
      break;
    }
  }
  if(r!=NULL && r!=NULL)
  {
     cout<<"false";
  }
  
  m=*start;
  int c=0;
  do
  {
    c++;
    m=m->next;
  } while (m!=r);
  cout<<"length is "<<c;
}
/*
void middle(struct node **start)
{
  struct node *t ,*r;
  t=*start;
  r=start->next;
  while(r!=NULL && r->next!=NULL)
  {
    t=t->next;
    r=r->next;
    r=r->next;
  }
  cout<<t<<" ";
}
*/


void merge(struct node **start1,struct node **start2)
{
    struct node *p,*q,*r;
    struct node *start3;
    start3=NULL;
    p=*start1;
    q=*start2;
    while(p!=NULL && q!=NULL)
    {
        if((p->info) < (q->info))
        {
            insend(&start3,p->info);
            p=p->next;
        }
        else 
        {
            insend(&start3,q->info);
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
  cout<<"merge"<<endl;
  while(r!=NULL)
    {
        cout<<r->info<<" ";
        r=r->next;
    }
    cout<<endl;
}

void unin(struct node **start1,struct node **start2)
{
  struct node *p,*q,*r;
    struct node *start3;
    start3=NULL;
    p=*start1;
    q=*start2;
    while(p!=NULL && q!=NULL)
    {
        if((p->info) < (q->info))
        {
            insend(&start3,p->info);
            p=p->next;
        }
        else if((p->info) == (q->info))
        {
            p=p->next;
            q=q->next;
        }
        else
        {
           insend(&start3,q->info);
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
  cout<<"union"<<endl;
  while(r!=NULL)
    {
        cout<<r->info<<" ";
        r=r->next;
    }
    cout<<endl;
}

void intersection(struct node **start1,struct node **start2)
{
   struct node *p,*q,*r;
    struct node *start3;
    start3=NULL;
    p=*start1;
    q=*start2;
    while(p!=NULL && q!=NULL)
    {
        if((p->info) < (q->info))
        {
            p=p->next;
        }
        else if((p->info) == (q->info))
        {
            insend(&start3,p->info);
            p=p->next;
            q=q->next;
        }
        else
        {
            q=q->next;   
        }
    }

  r=start3;
  cout<<"intersection"<<endl;
  while(r!=NULL)
    {
        cout<<r->info<<" ";
        r=r->next;
    }
    cout<<endl;
}

void diff(struct node **start1,struct node **start2)
{
    struct node *p,*q,*r;
    struct node *start3;
    start3=NULL;
    p=*start1;
    q=*start2;
    while(p!=NULL && q!=NULL)
    {
        if((p->info) < (q->info))
        {
            insend(&start3,p->info);
            p=p->next;
        }
        else if((p->info) == (q->info))
        {
            p=p->next;
            q=q->next;
        }
        else
        {
            q=q->next;   
        }
    }
   
    while(p!=NULL)
    {
        insend(&start3,p->info);
        p=p->next;
    }

  r=start3;
  cout<<"difference"<<endl;
  while(r!=NULL)
    {
        cout<<r->info<<" ";
        r=r->next;
    }
    cout<<endl;
}

void symm_diff(struct node **start1,struct node **start2)
{
    struct node *p,*q,*r;
    struct node *start3;
    start3=NULL;
    p=*start1;
    q=*start2;
    while(p!=NULL && q!=NULL)
    {
        if((p->info) < (q->info))
        {
            insend(&start3,p->info);
            p=p->next;
        }
        else if((p->info) == (q->info))
        {
            p=p->next;
            q=q->next;
        }
        else
        {
           insend(&start3,q->info);
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
  cout<<"symmetric difference"<<endl;
  while(r!=NULL)
    {
        cout<<r->info<<" ";
        r=r->next;
    }
    cout<<endl;
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
  insend(&start1,100);
  insend(&start1,200);
  insend(&start1,300);
  insend(&start1,400);
  traversing(&start1);
  cout<<start1<<endl;
  insbeg(&start2,5);
  insbeg(&start2,4);
  insbeg(&start2,3);
  insbeg(&start2,2);
  insbeg(&start2,1);
  insend(&start2,10);
  insend(&start2,20);
  insend(&start2,30);
  traversing(&start2);
  unin(&start1,&start2);
  merge(&start1,&start2);
  intersection(&start1,&start2);
  diff(&start1,&start2);
  symm_diff(&start1,&start2);
  //p=start1;
  //  for(int i=1;i<5;i++)
  //  {
  //      p=p->next;
  //  }
  //delaft(&p);
  //traversing(&start1);
  /*
  p=start;
  while(p->next!=NULL)
  {
    p=p->next;
  }
  cout<<p->info<<" ";
  q=start;
  while(q->info!=400)
  {
   q=q->next;
   cout<<q->info<<" ";
  }
  p->next=q;
  //traversing(&start);
  circular(&start);
  middle(&start);
 */
  return 0;
}