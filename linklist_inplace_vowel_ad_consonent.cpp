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

void delaft(struct node **r)
{
    struct node *p;
    (*r)->next=((*r)->next)->next;
    free((*r)->next);
}

void insbeg(struct node **start ,char x)
{
    struct node *p;
    p=getnode();
    p->info=x;
    p->next=(*start);
    (*start)=p;
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

void insbef(struct node **start,struct node **q,char x)
{
    struct node *p;
    p=getnode();
    p->info=x;
    p->next=(*q);
    (*start)=p;
}

// void consonent(struct node **start)
// {
//   struct node *p;
//   struct node *start1=NULL;
//   struct node *r;
//   struct node *q;
//   r=(*start);
//   p=(*start)->next;
//   q=(*start);
//   char c,y;
//   while(p->next!=NULL)
//   {
//     c=p->info;
//     cout<<c<<"* *"<<endl;
//     if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
//       {
//          y=q->info;
//          cout<<y<<"*"<<endl;
//          cout<<c<<" *"<<endl;
//         if(y!='a'&& y!='e'&& y!='i'&& y!='o'&& y!='u')
//         {
//           insbef(&(*start),&q,c);
//           q=(*start);
//           cout<<q->info<<"* * *"<<endl;
//           p=p->next;
//           delaft(&r);
//           cout<<p<<endl;
//         }
//         else
//         {
//           insaft(&q,y);
//           cout<<y<<endl;
//           p=p->next;
//           q=q->next;
//           delaft(&r);
//         }
//       }
//     else
//       {
//         p=p->next;
//         r=r->next;
//       }
//   }
//   cout<<"**"<<endl;
//   traverse(&(*start));
// }

void consnt(struct node **start)
{
  struct node *p;
  struct node *q;
  struct node *r;
  r=(*start);
  p=(*start)->next;
  q=(*start);
  char c,y,z;
  while(p!=NULL)
  {
    c=p->info;
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
    {
       z=p->info;
       p=p->next;
       insbeg(&(*start),z);
       delaft(&r);
    }
    else
    {
      p=p->next;
      r=r->next;
    }
  }
  traverse(&(*start));
}

// void consonant(struct node **start)
// {
//   struct node *p;
//   struct node *r;
//   struct node *q;
//   r=NULL;
//   p=NULL;
//   q=(*start);
//   char c,y,x;
//   while(q!=NULL)
//   {
//     c=q->info;
//     if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
//     {
//         q=q->next;
//         if(p==NULL)
//         {
//             if(r!=NULL)
//             {
//                 delaft(&r);
//             }
//             else
//             {
//                 delbeg(&(*start));
//                 insbeg(&(*start),c);
//                 p=(*start);
//             }
//         }
//         else
//         {
//             delaft(&q);
//             insbeg(&p,c);
//             p=p->next;
//         }
//     }
//     else
//     {
//         r=q;
//         q=q->next;
//     }
//   }   
// }

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
  consnt(&start);
  return 0;
}