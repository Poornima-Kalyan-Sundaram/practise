#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct node
{
	int data;
	node*next;
}*tmp=NULL,*front=NULL,*rear=NULL,*tmp1;

node*findbeforex(int obj)
{
	tmp=front;
	while(tmp)
	{

		
		if(tmp->next!=NULL)
		{
			if(tmp->next->data==obj)
			{
				return tmp;
			}
		}
		tmp=tmp->next;
	}

	return NULL;
}

bool removeafter(node*ptr)
{
	if(ptr->next->next)
	{
		node*del=ptr->next;

		tmp=ptr->next->next;
		ptr->next=tmp;
		
		del->next=NULL;
		free(del);
		return true;
		
	}
	return false;
}

void insertafter_ptrbefore(node*xptr,int obj)
{
	
}

void insert_ptrafter(node**xptr,int obj)
{
	tmp=(node*)malloc(sizeof(struct node));
	tmp->data=obj;
	tmp->next=(*xptr)->next;
	(*xptr)->next=tmp;		
}

void insert(int obj)
{
	tmp=(node*)malloc(sizeof(struct node));
	if(front==NULL)
	{
		front=rear=tmp;
		tmp->next=NULL;
		tmp->data=obj;
	}
	else
	{
		rear->next=tmp;
		tmp->data=obj;
		

		tmp->next=NULL;
		rear=tmp;
	}
}

int main()
{
	int x;
	cin>>x;

	insert(2);
	insert(13);
	insert(5);
	insert(1);
	insert(10);

	node*ptr;


	int tmp_data;

	ptr=findbeforex(x);

	node* someptr=ptr->next;
	if(ptr) //ptr is the pointer to the node before x
	{
		tmp=front;
		while(tmp->next&&tmp->next->data!=x)
		{
			if(tmp->next->data>x)
			{

				tmp_data=tmp->next->data;
				cout<<tmp_data;
				removeafter(tmp);
				tmp1=(node*)malloc(sizeof(struct node));
				tmp1->data=tmp_data;
				tmp1->next=someptr->next;
				ptr->next->next=tmp1;

			}
			tmp=tmp->next;
		}
		
	}
	else //if ptr is null and x is the first element
	{
		if(x==front->data)
		{
			//do the same as above
		}
	}	

	tmp=front;
	while(tmp)
	{
		cout<<tmp->data<<" ";		
		tmp=tmp->next;
	}
	return 0;
}
