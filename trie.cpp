//trie
#include<stdio.h>
#include<iostream>
using namespace std;

struct node
{
	int data;
	node*link;
	int num;
}*tmp;

void find(char*str)
{
	tmp=root;
	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i]!=tmp->data)
		break;
		//all adjacent nodes
		
	}
}

int main()
{
	return 0;
}
