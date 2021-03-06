//least common ancestor
#include<iostream>
#include<stdio.h>
#include<queue>
#include<stdlib.h>
#include<vector>
using namespace std;
struct node
{
	int data;
	node*left;
	node*right;
	node*parent;
	bool visited;
	int neighbor;
}*tmp,*root,*ptrtoten,*ptrtoone;

queue<node*>q;
queue<int>output;

void bfs(node*ptr)
{
	q.push(root);
	root->visited=true;
	while(!q.empty())
	{
		tmp=q.front();q.pop();
		cout<<tmp->data<<" ";
		tmp->visited=true;
		//now enque its UNVISITED adjacent nodes ->in this case left and right
		if(tmp->left)
		if(!tmp->left->visited)
		{q.push(tmp->left);}
		if(tmp->right)
		if(!tmp->right->visited)
		{q.push(tmp->right);}
	}
		
}

void dfs(node*ptr)
{
	if(ptr==NULL)
	return;
	else
	{
		
		if(ptr->parent||ptr==root)
		{
			cout<<ptr->data<<" ";
			output.push(ptr->data);
			dfs(ptr->parent);
		}
	}
}

node* insert(node*ptr,int o,node*parentptr)
{
	if(ptr==NULL)
	{
		tmp=(node*)malloc(sizeof(struct node));
		tmp->data=o;
		tmp->left=NULL;
		tmp->right=NULL;
		tmp->visited=false;
		tmp->parent=parentptr;
		tmp->neighbor=0;
		ptr=tmp;
		if(o==10)
		ptrtoten=ptr;
		if(o==1)
		ptrtoone=ptr;
	}
	else if(o<ptr->data)
	{
		ptr->left=insert(ptr->left,o,ptr);
	}
	else if(o>ptr->data)
	{
		ptr->right=insert(ptr->right,o,ptr);
	}
	return ptr;
}

void inorder(node*ptr)
{
	if(ptr==NULL)
	return ;
		
	cout<<ptr->data<<" ";
	int flag=0;
	//edit the neighbor information
	if(ptr->left)
	{
		flag=1;
		//inorder(ptr->left);
	}
	if(ptr->right&&flag==1)
	{
		ptr->right->neighbor=ptr->left->data;
		//inorder(ptr->right);
		//cout<<ptr->right->neighbor;
	}

	//now traverse
	if(ptr->left)
	{
		//flag=1;
		inorder(ptr->left);
	}
	if(ptr->right)
	{
		//ptr->right->neighbor=ptr->left->data;
		inorder(ptr->right);
	}

}

void print(node*ptr)
{
	if(ptr==NULL)
	return ;
		
	cout<<ptr->data<<" "<<ptr->neighbor<<endl;
	//now traverse
	if(ptr->left)
	{
		//flag=1;
		print(ptr->left);
	}
	if(ptr->right)
	{
		//ptr->right->neighbor=ptr->left->data;
		print(ptr->right);
	}

}


int main()
{	
	root=insert(root,5,NULL);
	insert(root,3,root);
	insert(root,2,root);
	insert(root,4,root);

	insert(root,6,root);
	insert(root,7,root);


	//dfs(ptrtoten);
	inorder(root);
	cout<<endl;

	print(root);
	return 0;
}
