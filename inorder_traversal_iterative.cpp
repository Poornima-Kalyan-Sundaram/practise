
#include<iostream>
#include<stdio.h>

using namespace std;

struct node
{
	int data;
	node*left;
	node*right;
}*root=NULL,*tmp;

node* insert(node*ptr,int obj)
{
	if(ptr==NULL)
	{
		tmp=(node*)malloc(sizeof(struct node));	
		tmp->data=obj;
		tmp->left=NULL;
		tmp->right=NULL;
		ptr=tmp;
	}
	if(obj<ptr->data)
	{
		ptr->left=insert(ptr->left,obj);
	}
	else
	{
		ptr->right=insert(ptr->right,obj);
	}
	return ptr;
}

void inorder(node*ptr)
{
	if(ptr==NULL)
	return;
	//left
	if(ptr->left)
	inorder(ptr->left);
	
	//visit ptr
	cout<<" "<<ptr->data<<endl;

	//right
	if(ptr->right)
	inorder(ptr->right)
}

int main()
{

	root=insert(root,10);
	insert(root,5);
	insert(root,3);
	insert(root,11);	
	return 0;
}
