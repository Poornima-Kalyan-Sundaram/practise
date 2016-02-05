#include<iostream>
#include<stdio.h>
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

	//first element
	if(front==NULL)
	{
		front=rear=tmp;
		tmp->next=NULL;
		tmp->data=obj;
	}
	else
	{
		rear->next=tmp;
		rear=tmp;
		tmp->data=obj;
		tmp->next=NULL;
	}	
}

int remove()
{
	//only one element
	if(rear==front)
	{
		
		int return_val=rear->data;
		tmp=rear;
		rear=front=NULL;
		free(tmp);
		return return_val;			
	}
	else
	{
		//move the ptr to second to last element
		int return_val=front->data;
		tmp=front;
		front=tmp->next;
		tmp->next=NULL;
		free(tmp);
		return return_val;	
	}
}
int main()
{
	insert(10);
	insert(11);
	insert(12);
	insert(13);	
	
	cout<<remove()<<endl;	
	cout<<remove()<<endl;	
		
	return 0;
}
