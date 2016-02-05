/*
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct node
{
	int data;
	node*next;
	node*prev;
	
}*front=NULL,*rear=NULL,*tmp,*tmp_prev,*tmp_next;

void insert(int obj)
{
	tmp=(node*)malloc(sizeof(struct node));
	if(front==NULL)
	{
		front=rear=tmp;
		tmp->next=tmp;
		tmp->prev=tmp;
		tmp->data=obj;
	}
	else
	{
		
		
		tmp->next=front;
		tmp->prev=rear;
		tmp->data=obj;

		rear->next=tmp;
		rear=tmp;
		
		front->prev=tmp;
		

	}
}

int remove()
{
	int ret_val=-1;
	if(front==NULL)
	{
		
	}
	else if(front==rear)
	{
		ret_val=rear->data;
		tmp=front;
		front=rear=NULL;
		free(tmp);
	}
	else
	{
		tmp=front;
		ret_val=front->data;

		tmp_prev=front->prev;
		tmp_next=front->next;
	
		tmp_next->prev=tmp_prev;
		tmp_prev->next=tmp_next;
			
		front=tmp_next;
		
		free(tmp);
	}
	
	return ret_val;
}

int main()
{

		
	insert(10);
	insert(2);
	cout<<remove();
	return 0;
}
