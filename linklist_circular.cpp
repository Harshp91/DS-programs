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

void insafter(struct node **q,int x)
{
    struct node *r,*p,*Z;
    p=getnode();
    r=(*q)->next; 
    p->info=x;
    (*q)->next=p;
    p->next=r;
}

void insbeg(struct node **cstart ,int x)
{
    struct node *p;
    p=getnode();
    if((*cstart)!=NULL)
    {
        p->next=(*cstart)->next;
        (*cstart)->next=p;
        p->info=x;
    }
    else
    {
      *cstart=p;  
      (*cstart)->next=p;
       p->info=x;
    }

    //p->next=(*cstart)->next;
    //(*cstart)->next=p;
    /*
    if((*cstart)!=NULL)
    {
        p->next=(*cstart)->next;
        (*cstart)->next=p;
    }
    else
    {
      *cstart=p;  
      (*cstart)->next=p;
    }
    */
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

void delaft(struct node **q)
{
    struct node *r,*p,*Z;
    int x;
    p=(*q)->next;
    (*q)->next=p->next;
    x=p->info;
    free(p);
    //traversing(&(*q));
}

int delbeg(struct node **cstart)
{
    struct node *p;
    p = (*cstart)->next;
    (*cstart)->next = p->next;
    if((*cstart)->next == (*cstart))
    {
        cstart=NULL;
    }
    int x = p->info;
    free(p);
}

int delend(struct node **cstart)
{
    struct node *p;
    struct node *q;
    q = (*cstart)->next;
    p = (*cstart)->next;
    q = NULL;
    while (p->next != (*cstart))
    {
        p = p->next;
    }
    p->next = (*cstart)->next;
    (*cstart)=p;
    if((*cstart)==NULL)
    {
        cout<<"deletion not possible"<<endl;
    }
    free(p);
}

void traversal(struct node **cstart)
{
    struct node *p;
    p=(*cstart)->next;
    while(p!=(*cstart))
    {
        cout<<p->info<<endl;;
        p=p->next;
    }
    cout<<p->info;
}

void concat(struct node **cstart1,struct node **cstart2)
{
    struct node *p,*q,r;
    p=(*cstart1)->next;
    q=(*cstart2)->next;
    (*cstart1)->next=q;
    (*cstart2)->next=p;
    traversal(&(*cstart2));
}

int main()
{
  struct node *cstart= NULL;
  struct node *p,*q;
  insbeg(&cstart,50);
  insbeg(&cstart,40);
  insbeg(&cstart,30);
  insbeg(&cstart,20);
  insbeg(&cstart,10);
  insafter(&cstart,70);
  insafter(&cstart,80);
  insafter(&cstart,90);
  //insend(&cstart1,100);
  //insend(&cstart1,200);
  //insend(&cstart1,300);
  //insend(&cstart1,400);
  traversal(&cstart);
  cout<<endl;
  cout<<endl;
  concat(&cstart1,&cstart2);
  return 0;
}