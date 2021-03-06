#include<iostream>
#include<stdio.h>
using namespace std;

struct node
{
int visited;
int dist;
int prev;
}n[10];

int num_nodes=4;

int adj_mat[4][4]={0,1,2,0,
		   0,0,0,3,
		   0,0,0,4,
	           0,0,0,0
		};


void initialise_dist_visited()
{
	for(int i=0;i<num_nodes;i++)
	{
		n[i].visited=0;
		n[i].dist=9999;
		n[i].prev=-1;
	}
}


int find_mindist(int source)
{
	int min=9999,minnode=-1;
	for(int i=0;i<num_nodes;i++)
	{
		
		if(adj_mat[source][i]!=0&&n[i].visited==0)
		{
			if(n[i].dist<min)
			{
				minnode=i;
				min=n[i].dist;
			}
		}
	}
	return minnode;

}
void dijsktra()
{
	int u=0;//source;
	n[0].visited=1;
	n[0].dist=0;
	//loop!
	int source;
	do
	{
		cout<<u;
		source=u;
		//for every node v adj to u , if the min dist to reach them is via u, then update their distances
		for(int v=0;v<num_nodes;v++)
		{
			
			if((adj_mat[u][v]+n[u].dist<n[v].dist)&&(adj_mat[u][v]!=0))
			{
				n[v].dist=adj_mat[u][v]+n[u].dist;
				n[v].prev=u;
			}
		}
	u=find_mindist(source); //find the node which has the least possible distance from u and is unvisited
	n[source].visited=1;
	}while(u!=-1);
	for(int i=0;i<num_nodes;i++)
	{
		cout<<"\n"<<n[i].prev;
	}

}

int main()
{
	initialise_dist_visited();
	dijsktra();
	return 0;
}

