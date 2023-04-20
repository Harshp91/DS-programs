#include<iostream>
using namespace std;
#define True 1

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *makenode(int x)
{
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	p->data=x;
	p->left=NULL;
	p->right=NULL;
	return p;
}

void Pre_order_traversal(struct node **t)
{
	if((*t)!=NULL)
	{
		cout<<(*t)->data<<" ";
		Pre_order_traversal(&((*t)->left));
		Pre_order_traversal(&((*t)->right));
	}
}
void In_order_traversal(struct node **t)
{
	if((*t)!=NULL)
	{
		In_order_traversal(&((*t)->left));
		cout<<(*t)->data<<" ";
		In_order_traversal(&((*t)->right));
	}
}
void Post_order_traversal(struct node **t)
{
	if((*t)!=NULL)
	{
		Post_order_traversal(&((*t)->left));
		Post_order_traversal(&((*t)->right));
		cout<<(*t)->data<<" ";
	}
}

void insert(struct node **t,int x)
{
  struct node *p;
  struct node *q;
  p=*t;
  q=NULL;
  if(*t==NULL)
  {
    *t=makenode(x);
  }
  else
  {
     while(p!=NULL)
    {
      if(x < p->data)
      {
          q=p;
          p=p->left;
      }
      else
      {
          q=p;
          p=p->right;
      }
    }
    if(x< q->data)
    {
      q->left=makenode(x);
    }
    else
    {
      q->right=makenode(x);
    }
  }
}

void min(struct node **t)
{
    while((*t)->left!=NULL)
    {
       (*t)=(*t)->left;
    }
    cout<<(*t)->data<<endl;
}

void max(struct node **t)
{
    while((*t)->right!=NULL)
    {
        (*t)=(*t)->right;
    }
    cout<<(*t)->data<<endl;
}

void search(struct node **t,int key)
{
    while((*t)!=NULL)
    {
        //cout<<(*t)->data<<" ";
        if((*t)->data==key)
        {
            cout<<1<<endl;
            break;
        }
        else
        {
            if(key < (*t)->data)
            {
                (*t)=(*t)->left;
                //cout<<(*t)->data<<" ";
            }
            else
            {
               (*t)=(*t)->right;
               //cout<<(*t)->data<<" ";
            }
        }
    }
    cout<<0<<endl;
}

int main()
{
	struct node *t=NULL;
    struct node *p;
    insert(&t,100);
    insert(&t,50);
    insert(&t,150);
    insert(&t,40);
    insert(&t,70);
    insert(&t,120);
    insert(&t,300);
    insert(&t,60);
    insert(&t,250);
    insert(&t,55);
    insert(&t,200);
    insert(&t,260);
    In_order_traversal(&t);
    cout<<endl;
    p=t;
    max(&p);
    min(&t);
 return 0;
}
