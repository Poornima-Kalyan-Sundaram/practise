#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/*
4.1 
	find the route between two nodes 
	1.bfs
	2.dfs
*/
struct node
{
	int data;
	node*next1;
	node*next2;
}*front,*rear,*tmp_1,*tmp_2,*tmp_3,*tmp_4;


void visit(node*ptr)
{
	cout<<ptr->data<<" "<<endl;
}

void bfs(node*ptr)
{


	if(ptr==NULL)
	{
		return;
	}

	visit(ptr);

	if(ptr->next1)	
	{
		bfs(ptr->next1);
	}

	if(ptr->next2)
	{
		bfs(ptr->next2);
	}

}



void dfs(node*ptr)
{

	if(ptr==NULL)
	return;

	if(ptr->next1)	
	{
		dfs(ptr->next1);

	}

	if(ptr->next2)
	{
		dfs(ptr->next2);

	}

		visit(ptr);

}

int main()
{
	
	tmp_1=(node*)malloc(sizeof(struct node));
	tmp_2=(node*)malloc(sizeof(struct node));
	tmp_3=(node*)malloc(sizeof(struct node));
	tmp_4=(node*)malloc(sizeof(struct node));

	tmp_1->data=1;
	tmp_1->next1=tmp_2;
	tmp_1->next2=tmp_3;

	tmp_2->data=2;
	tmp_2->next1=NULL;
	tmp_2->next2=NULL;
	
	tmp_3->next1=tmp_4;
	tmp_3->next2=NULL;
	tmp_3->data=3;

	tmp_4->next1=NULL;
	tmp_4->next2=NULL;
	tmp_4->data=4;	

	bfs(tmp_1);
	cout<<"\n==========\n";
	dfs(tmp_1);
		
	return 0;
}
