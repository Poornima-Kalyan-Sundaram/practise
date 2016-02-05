#include<iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
/*
stack as a linked list
*/

struct node
{
	int data;
	node *next;
}*top=NULL,*tmp,*front;

void push(int obj)
{

	tmp=(node*)malloc(sizeof(struct node));
	//first element
	if(top==NULL)	
	{
		tmp->data=obj;
		tmp->next=NULL;	
		top=tmp;
		front=tmp;	
	}
	else
	{
		top->next=tmp;
		top=tmp;
		tmp->next=NULL;
		tmp->data=obj;
	}	
}

int pop()
{
	//slide to the top element
	tmp=front;
	while(tmp->next->next!=NULL)
	{
		tmp=tmp->next;
	}
	
	int return_val=tmp->next->data;
	
	tmp->next=NULL;
	return return_val;
}


int main()
{
	push(10);
	push(15);
	push(30);
	cout<<pop();
	return 0;
}
