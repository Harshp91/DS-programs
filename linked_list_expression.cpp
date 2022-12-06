#include<iostream>
#include<stdlib.h>
using namespace std;

void addition(struct node **poly1,struct node **poly2);

struct node
{
    int coef;
    int exp;
    struct node *next;
};

struct node *getnode()
{
  struct node *p;
  p=(struct node*)malloc(sizeof(struct node));
  return p;
}

/*
int delbeg(struct node **start)
{
    struct node *p;
    p = *start;
    *start = *start->next;
    int x = p->info;
    free(p);
    return x;
}

void insbeg(struct node **start ,int x,int y)
{
    struct node *p;
    p=getnode();
    p->info=x;
    p->coef
    p->next=*start;
    *start=p;
    p->info=x;
    p->next=*start;
    *start=p;
}
*/

void insbeg(struct node **start ,int x,int y)
{
    struct node *p;
    p=getnode();
    p->coef=x;
    p->exp=y;
    p->next=*start;
    *start=p;
}

void insend(struct node **start,int x,int y)
{
  struct node *p,*q;
  q=*start;
  if(q==NULL){
	insbeg(start,x,y);
  }
  else{
  while(q->next!=NULL)
  {
    q=q->next;
  }
  p=getnode();
  p->coef=x;
  p->exp=y;
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
        cout<<p->coef;
        cout<<"x^"<<p->exp<<" ";
        p=p->next;
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

void insafter(struct node **q,int x,int y)
{
    struct node *r,*p,*Z;
    p=getnode();
    p->coef=x;
    p->exp=y;
    r=(*q)->next; 
    p->next=r;
    (*q)->next=p; 
}

void subs(struct node **start1,struct node **start2)
{
    struct node *p;
    struct node *q;
    struct node *start3;
    struct node *r;
    start3=NULL;
    p=*start1;
    q=*start2;
    while(p!=NULL && q!=NULL)
    {
        if(p->exp == q->exp)
        {
            insend(&start3,p->coef +(-q->coef),p->exp);
            p=p->next;
            q=q->next;
        }
        else
        {
            if(p->exp > q->exp)
            {
                insend(&start3,p->coef,p->exp);
                p=p->next;
            }
            else
            {
                insend(&start3,(-q->coef),q->exp);

                q=q->next;
            }
        }
    }
    traversing(&start3);
}

void orderinsert(struct node **start3,int x , int y)
{
    struct node *p,*q;
    p=*start3;
    while(p!=NULL)
    {
        if(p->exp==y)
        {
            insafter(&p,x,y);
            break;
        }
        else if(p->next==NULL)
        {
            insend(&p,x,y);
            break;
        }
        else if(p==NULL)
        {
            insbeg(&p,x,y);
            break;   
        }
        else 
        {
            p=p->next;
        }
    }
}

void multiply(struct node **poly1,struct node **poly2)
{
    struct node *p;
    struct node *q;
    struct node *start3;
    start3=NULL;
    p=*poly1;
    q=*poly2;
    while(q!=NULL )
    {
        p=*poly1;
        while(p!=NULL)
        {
            orderinsert(&start3,(p->coef)*(q->coef),(p->exp)+(q->exp));
            p=p->next;
        }
        q=q->next;
    }
    p=start3;
    //while(p->next!=NULL)
    //{
    //    if(p->exp==(p->next)->exp)
    //    {
    //        p->coef = (p->coef)+((p->next)->coef);
    //        delaft(&p);
    //    }
    //    else
    //    {
    //        p=p->next;
    //    }
    //}
    traversing(&start3);
}

void addition(struct node **poly1,struct node **poly2)
{
    struct node *p;
    struct node *q;
    struct node *start3;
    start3=NULL;
    p=*poly1;
    q=*poly2;
    while(p!=NULL && q!=NULL)
    {
        if(p->exp == q->exp)
        {
            //y=p->coef + q->coef;
            insend(&start3,p->coef + q->coef,p->exp);
            p=p->next;
            q=q->next;
        }
        else
        {
            if(p->exp > q->exp)
            {
                insend(&start3,p->coef,p->exp);
                p=p->next;
            }
            else
            {
                insend(&start3,q->coef,q->exp);
                q=q->next;
            }
        }
    }
    traversing(&start3);
}

int main()
{
    struct node *start1= NULL;
    struct node *start2= NULL;
    struct node *p,*q;
    cout<<"ente the coef and exp of the square exp"<<endl;
    insend(&start1,3,2);
    insend(&start1,5,1);
    insend(&start1,4,0);
    traversing(&start1);
    cout<<endl;
    p=start2;
    insend(&start2,4,2);
    insend(&start2,1,1);
    insend(&start2,2,0);
    traversing(&start2);
    cout<<endl<<endl;
    cout<<"after summation"<<endl;
    addition(&start1,&start2);
    cout<<endl<<endl;
    cout<<"after deletion"<<endl;
    subs(&start1,&start2);
    cout<<endl<<endl;
    cout<<"after multiplication "<<endl;
    multiply(&start1 , &start2);
    //traversing(&start2);
  return 0;
}