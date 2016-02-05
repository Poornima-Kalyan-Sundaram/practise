#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;


struct node
{
	int data;
	node*left;
	node*right;
	bool visited;
}*root=NULL,*tmp;

int queue[10];
node *nodeptrsq[10];

int rear=-1,front=-1;
void enque(int obj,node*ptr) //insert at rear
{
	if(front==-1)
	{
		front=rear=0;
		queue[rear]=obj;
		nodeptrsq[rear]=ptr;
	}
	else
	{
		queue[++rear]=obj;
		nodeptrsq[rear]=ptr;

	}
}

node*nowvisitingptr=NULL;
int deque()
{
	int return_val=-1;
	if(front==-1)
	{
	nowvisitingptr=NULL;
	return return_val;}
	else if(front==rear)
	{
		return_val=queue[front];
		nowvisitingptr=nodeptrsq[front];
		front=rear=-1;
		cout<<"only one element";
		return return_val;
	}
	else
	{
		return_val=queue[front];
		nowvisitingptr=nodeptrsq[front];
		front--;
		return return_val;
	}
}

node* insert(int obj,node*ptr)
{
	if(ptr==NULL)
	{
		tmp=(node*)malloc(sizeof(struct node));
		tmp->data=obj;
		tmp->left=NULL;
		tmp->right=NULL;
		tmp->visited=false;
		ptr=tmp;
	}
	else if(obj<ptr->data)
	{
		ptr->left=insert(obj,ptr->left);
	}
	else
	{
		ptr->right=insert(obj,ptr->right);
	}
	return ptr;
}

void bfs(node*root)
{
	int i=0;
	enque(root->data,root);
	root->visited=true;
	while(front!=-1)
	{
		cout<<"loop";
		cout<<front;
		cout<<deque()<<"deque"<<endl;
		

		if(nowvisitingptr->left)
		if(!nowvisitingptr->left->visited)
		{
			cout<<"entering left"<<endl;
		enque(nowvisitingptr->left->data,nowvisitingptr->left);
		nowvisitingptr->left->visited=true;
		}

		if(nowvisitingptr->right)
		if(!nowvisitingptr->right->visited)
		{		

			cout<<"entering right"<<endl;
		nowvisitingptr->right->visited=true;
		enque(nowvisitingptr->right->data,nowvisitingptr->right);
		}
		
	}
	
}

int main()
{
	root=insert(2,root);
	insert(3,root);
	/*insert(0,root);
	insert(10,root);
	*/
	bfs(root);
	return 0;
}
