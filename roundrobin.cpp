/*round robin*/
#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;

struct process
{
	int num;
	int time_remaining;
}input_process;


int time_slice=2,q_capacity=5,curr_size=0,r=-1,f=-1;
queue<process>q;
/*
create circulr q- insert and delete operations
*/


void insert(process p)
{
	if(curr_size==q_capacity)
	{
		cout<<"q full"<<endl;
		return;
	}
	else //q not full
	{
		if(r==-1&&f==-1)//first insertion
		{
			r=0;f=0;
		}
		else if(r==q_capacity-1)
		{
			r=0;
		}
		else
		{
			r++;
		}
		curr_size++;
		q.push(p);
	}
}

process remove()
{
	process p;
	p.num=-1;//q empty condition
	if(curr_size==0)
	{
		cout<<"q empty";
	}
	else //q not empty
	{ 
		 if(curr_size==1)
		{
			f=0;
			
		}
		else if(f==q_capacity-1) //only one element
		{
			f=-1;
			r=-1;
		}
		else
		{
			f++;
		}
		curr_size--;
		p=q.front();
		q.pop();
		
	}
	return p;
	
}

int main()
{
	process p;
	p.num=1;
	p.time_remaining=10;	
	insert(p);
	p.num=2;
	p.time_remaining=10;	
	insert(p);
	p.num=3;
	p.time_remaining=5;	
	insert(p);

	process ret_process;
	ret_process.num=0;
	while(ret_process.num!=-1)
	{
		
		ret_process=remove();
		if(re_process.num==-1)
		break;
		cout<<"now running process#"<<ret_process.num<<endl;
		ret_process.time_remaining-=time_slice;
		if(ret_process.time_remaining>0)
		insert(ret_process);
		
	}
	return 0;
}

