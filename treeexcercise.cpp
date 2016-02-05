//insert into the binary tree
//convert a tree into sorted array
//convert the sorted array into a tree
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct node
{
	int data;
	node*left;
	node*right;
	node*parent;
}*root=NULL,*tmp,*lastinsertedptr;

int arr[10],top=-1;


node*insert(node*pointer,int obj,node*parentptr)
{

	if(pointer==NULL)
	{
		tmp=(node*)malloc(sizeof(struct node));
		tmp->left=NULL;
		tmp->right=NULL;
		if(pointer==root)
		tmp->parent=NULL;
		else
		{tmp->parent=parentptr;cout<<"parent data"<<parentptr->data<<"my data"<<obj<<endl;}
		tmp->data=obj;
		pointer=tmp;
		lastinsertedptr=tmp;
	}

	else if(obj>pointer->data)
	{
		pointer->right=insert(pointer->right,obj,pointer);
	}
	else
	{
		pointer->left=insert(pointer->left,obj,pointer);

	}
	return pointer;
}




//inorder traversal with stack push
void converttree_to_arr(node*pointer)
{
	if(pointer==NULL)
	return;
	if(pointer->left)
	converttree_to_arr(pointer->left);
	cout<<endl;
	cout<<"data is"<<pointer->data;
	arr[++top]=pointer->data;

	if(pointer->right)
	converttree_to_arr(pointer->right);
	
}


void heap_insert(node*ptr)
{
	if(ptr==NULL||ptr->parent==NULL)
	{cout<<"parent is null";return;}
	if(ptr->data<ptr->parent->data)
	{
		
		//precolate up
		int temp;
		temp=ptr->data;
		ptr->data=ptr->parent->data;
		ptr->parent->data=temp;
		
		//parent's data ie now ptr's data should go the right or left
		
		//anything greater than the parent goes to the right
		if(ptr->parent->left>ptr->parent->right || (!ptr->left))
		{
			
		}
		else
		{
			
		}		

		cout<<"precolate"<<endl;
		heap_insert(ptr->parent);

	}

}


//heap insert operation ->precolate up (simply swap the data)
void convert_btreetobst(int obj)
{
	
	node*lastnodeptr=insert(root,obj,root);

	if(root==NULL)
	{root=lastnodeptr;}
	else
	lastnodeptr=lastinsertedptr;

	heap_insert(lastnodeptr);	

	if(lastnodeptr->parent==NULL)
	cout<<"last node ptr parents data"<<endl;	

}

int main()
{

	
	convert_btreetobst(4);		
	convert_btreetobst(1);		
	converttree_to_arr(root);
	return 0;
}
