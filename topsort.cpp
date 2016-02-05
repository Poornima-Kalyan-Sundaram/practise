#include<iostream>
#include<stdio.h>
using namespace std;
//count the indgreee of all the vertices
//perform a dfs and push to stack


//adj_matrix representation


int adj_mat[4][4]={0,1,1,0,
		   0,0,0,1,
		   0,0,0,1,
	           0,0,0,0
		};


int indegree[4]={0,0,0,0};
int visited[4]={0,0,0,0};

void find_indegree()
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(adj_mat[i][j]==1)
			{
				indegree[j]++;
			}
		}
	}
	
}

int findzeroindegree()
{
	for(int i=0;i<4;i++)
	{
		if(indegree[i]==0)
		return i;
	}
	return -1;
}

void topsort()
{
	int vertex=-1;
	while((vertex=findzeroindegree())!=-1)
	{
		cout<<vertex<<" "<<endl;
		visited[vertex]=1;
		//remove the connections from vertex's outgoing edges
		for(int i=0;i<4;i++)
		{
			if(adj_mat[vertex][i]=1)
			{
				adj_mat[vertex][i]=0;
				//cout<<"connected to"<<i;
				indegree[i]--;
			}
		}
	}

	//now print all the lone vertices
	for(int i=0;i<4;i++)
	{
		if(visited[i]==0)
		cout<<i;
	}
	
}


int main()
{
	find_indegree();
	topsort();
	return 0;
}
