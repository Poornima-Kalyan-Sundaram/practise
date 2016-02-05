#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	node*next;
}*front=NULL,*rear=NULL,*tmp;

void insert(int obj)
{
	tmp=(node*)malloc(sizeof(struct node));
	if(front==NULL)
	{
		tmp->next=NULL;
		front=rear=tmp;
		tmp->data=obj;
	}
	else
	{
		tmp->next=NULL;
		tmp->data=obj;
		rear->next=tmp;
		rear=tmp;	
	}
}

void ptr_insertion(node*ptr)
{
	if(front==NULL)
	{
		front=rear=ptr;
	}
	else
	{
		rear->next=ptr;
		rear=ptr;
	}
	ptr->next=NULL;

}

void recursion(node*ptr,node*prev)
{
		if(ptr==NULL)
		{
			front=rear=NULL;
			return;
		
		}
		else
		{
			recursion(ptr->next,ptr);
			//operate on ptr
			if(prev)
			prev->next=NULL;
			ptr_insertion(ptr);
			
		}
}
void print()
{
	tmp=front;
	while(tmp)
	{
		cout<<tmp->data<<" "<<endl;		
		tmp=tmp->next;
	}
}
int main()
{
	insert(1);
	insert(2);
	insert(3);
	print();

	recursion(front,NULL);
	print();
	return 0;
}

