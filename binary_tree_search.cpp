#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct node
{
	node*left;
	node*right;
	int data;
}*root=NULL,*tmp;

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
int binary_search(int key,node*ptr)
{
	if(ptr->data==key)
	{
		return key;
	}
	
	else if(key<ptr->data)
	binary_search(key,ptr->left);
	else
	binary_search(key,ptr->right);
	
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
int main()
{
	root=insert(10,root);
	cout<<root->data<<endl;
	insert(2,root);
	insert(3,root);
	insert(22,root);
	print(root);
	
	if(binary_search(3,root)==3)
	cout<<"found"<<endl;
	return 0;
}
