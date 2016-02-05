//store the nodes of a tree based on their depth 
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<queue>
using namespace std;
#define max_children 2
struct node
{
	int data;
	bool visited;
	int num_children; //lets limit to a tree that has two children
	node*child[max_children];
}*tmp,*root=NULL,*ptr;

node* insert(int obj,node*ptr)
{
	if(ptr==NULL)
	{
		tmp=(node*)malloc(sizeof(struct node));
		tmp->data=obj;
		tmp->num_children=0;
		for(int i=0;i<max_children;i++)
		tmp->child[i]=NULL;
		tmp->visited=false;
	
		ptr=tmp;
	}
	else if(ptr->num_children<max_children)
	{
		ptr->child[ptr->num_children]=insert(obj,ptr->child[ptr->num_children]);
		ptr->num_children++;
	}
	else //one of ptr's child has space to add a new node
	{
		for(int i=0;i<max_children;i++)
		{
			if(ptr->child[i])
			{
				if(ptr->child[i]->num_children<max_children)
				{
					int index=ptr->child[i]->num_children;
					ptr->child[i]->child[index]=insert(obj,ptr->child[i]->child[index]);
					ptr->child[i]->num_children++;
					break;
				}
			}
		}
	}
	return ptr;
}
queue<node*>q;
void bfs(node*root)
{
	q.push(root);
	root->visited=true;
	while(!q.empty())
	{
		tmp=q.front();
		cout<<tmp->data<<" ";
		q.pop();
		for(int i=0;i<tmp->num_children;i++)
		{
			if(tmp->child[i])
			{
				tmp->child[i]->visited=true;
				q.push(tmp->child[i]);
			}
		}
	}
}
	
int main()
{	
	root=insert(3,root);
	insert(1,root);
	insert(2,root);
	insert(5,root);
	bfs(root);
	return 0;
}
