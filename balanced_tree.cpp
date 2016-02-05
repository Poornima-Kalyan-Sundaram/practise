#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;
	node*left;
	node*right;
}*tmp,*root=NULL;

struct list
{
	int data;
	list*next;
}*t;

/*
node* insert(int obj,node*ptr)
{
	
	if(ptr==NULL)
	{
		
		ptr=(node*)malloc(sizeof(struct node));
		ptr->data=obj;
		ptr->left=NULL;
		ptr->right=NULL;
		return ptr;

	}
	

	if(ptr->data>obj)
	{
		ptr->left=insert(obj,ptr->left);			
	}
	else	
	{
		cout<<" right tree\n"<<obj<<"\n    \n"<<endl;
		ptr->right=insert(obj,ptr->right);			
	}


	
}
*/

node* insert(int obj,node*ptr)
{
	if(ptr==NULL)
	{
		
			tmp=(node*)malloc(sizeof(struct node));
			tmp->data=obj;
			tmp->left=NULL;
			tmp->right=NULL;
			ptr=tmp;
	}
	else if(obj<ptr->data) //insert to the left side
	{
			ptr->left=insert(obj,ptr->left);
	}
	else //insert to the right side
	{
			ptr->right=insert(obj,ptr->right);	
	}	
	return ptr;

}


void create_list()
{
}


void print(node*ptr)
{
	if(ptr==NULL)
	return;
	
	cout<<" "<<ptr->data<<" "<<endl;
	
	if(ptr->left)
	print(ptr->left);
	if(ptr->right)
	print(ptr->right);
}


void update(node*ptr,int val)//a bfs search modification
{
	if(ptr==NULL)
	return;
	
	ptr->data+=val;

	if(ptr->left)
	{
		update(ptr->left,ptr->data);
	}
	if(ptr->right)
	{
		update(ptr->right,ptr->data);

	}	
}


int main()
{

	root=insert(10,root);
	insert(2,root);
	insert(3,root);
	insert(4,root);


	print(root);
	update(root,0);
	print(root);

	return 0;

}
