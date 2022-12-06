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
    *start = *start->next;
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

void middle(struct node **start)
{
  struct node *t;
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
