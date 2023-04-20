#include<iostream>
#include<bits/stdc++.h>
using namespace std;

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

void createtree(struct node **tree)
{
    int choice;
    struct node *p;
    int d;
    d=(*tree)->data;
    cout<<"is left of"<<d<< "exists? (1/0) ";
    cin>>choice;
    int x;
    if(choice==1)
    {
        cout<<"input the data of left"<<d;
        cin>>x;
        p=makenode(x);
        (*tree)->left=p;
        createtree(&p);
    }

    cout<<"is right of"<<d<< "exists? (1/0) ";
    cin>>choice;
    if(choice==1)
    {
        cout<<"input the data of right"<<d;
        cin>>x;
        p=makenode(x);
        (*tree)->right=p;
        createtree(&p);
    }
}

int main()
{
	struct node *root=NULL;
    struct node *p;
    struct node *img=NULL;
    int x,y; 
    cout<<"enter the first node value"<<endl;
    cin>>x;
    root=makenode(x);
    createtree(&root);
    
    queue< node* >q;
    q.push(root);
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        if(p->left!=NULL)
        {
            q.push(p->left);
        }
        if(p->right!=NULL)
        {
            q.push(p->right);
        }
        cout<<p->data;
    }

 return 0;
}