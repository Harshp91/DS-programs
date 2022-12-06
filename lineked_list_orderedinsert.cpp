#include<iostream>
#include<stdlib.h>
#include<array>
using namespace std;

void ordered_arrange(struct node **start,int x);
void order_insert(int a[],int b[]);

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

void order_insert(int a[],int b[],int n,int m)
{
    int i=0,j=0;
    cout<<n<<" "<<m<<" ";
    struct node *start1,*start2;
    for(i=0;i<n;i++)
    {
        ordered_arrange(&start1,a[i]);
        i++;
    }
    for(j=0;j<m;j++)
    {
        ordered_arrange(&start2,b[j]);
        j++;
    }
    merge(&start1,&start2);
}

void ordered_arrange(struct node **start,int x)
{
   struct node *p,*q;
   p=*start;
   q=NULL;
   while(p!=NULL && x>=(p->info))
   {
     q=p;
     p=p->next;
   } 
   if(q==NULL)
   {
     insbeg(&(*start), x);
   }
   else
   {
    insafter(&p,x);
   }
}

int main()
{
  struct node *start1= NULL,*start2= NULL;
  struct node *p,*q;
  
  int n,m,i;
  /*
  cout<<"enter the two linked list size"<<endl;
  cin>>n>>m;
  int a[100],b[100];
  cout<<"enter the first linked list element"<<endl;
  for(i=0;i<n;i++)
  {
    cin>>a[i];
  }
  cout<<"enter the second linked list element"<<endl;
  for(i=0;i<m;i++)
  {
    cin>>b[i];
  }
  */
  ordered_arrange(&start1,3);
  ordered_arrange(&start1,4);
  ordered_arrange(&start1,6);
  ordered_arrange(&start1,1);
  traversing(&start1);
  return 0;
}