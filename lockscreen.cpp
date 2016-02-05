#include<iostream>
#include<stdio.h>

#define left -1
#define right 1
#define top -3
#define down 3
#define diag1down 2
#define diag1up -2
#define diag2up -4
#define diag2down 4

using namespace std;



bool valid(int x)
{
	if(x>=1&&x<=3)
	return true;
	else
	return false;
}

bool visited[10]={false,
		false,false,false,
		false,false,false,
		false,false,false};

int num_of_path=0;

void lock(int n,int num_steps_left)
{
	if(num_steps_left==1&&valid(n)&&!visited[n])
	{
		for(int j=1;j<=9;j++)
		visited[j]=false;

		cout<<n;
		num_of_path++;
		cout<<endl;
		return;
	}
	else if(valid(n)&&!visited[n])
	{
		visited[n]=true;
		
		cout<<n<<" ";
		if(!visited[n+left])
		lock(n+left,num_steps_left-1);
		else
		lock(n+2*left,num_steps_left-1);
	
		if(!visited[n+right])	
		lock(n+right,num_steps_left-1);
		else
		lock(n+2*right,num_steps_left-1);

		if(!visited[n+top])	
		lock(n+top,num_steps_left-1);
		else
		lock(n+2*top,num_steps_left-1);

		if(!visited[n+down])	
		lock(n+down,num_steps_left-1);
		else
		lock(n+2*down,num_steps_left-1);

		if(!visited[n+diag1down])	
		lock(n+diag1down,num_steps_left-1);
		else
		lock(n+2*diag1down,num_steps_left-1);

		if(!visited[n+diag1up])	
		lock(n+diag1up,num_steps_left-1);
		else
		lock(n+2*diag1up,num_steps_left-1);


		if(!visited[n+diag2down])	
		lock(n+diag2down,num_steps_left-1);
		else
		lock(n+2*diag2down,num_steps_left-1);

		if(!visited[n+diag2up])	
		lock(n+diag2up,num_steps_left-1);
		else
		lock(n+2*diag2up,num_steps_left-1);

	}
	
}

int main()
{

/*	for(int i=1;i<=9;i++)
	{	//initialise visited array
			for(int j=1;j<=9;j++)
			visited[j]=false;
*/		lock(2,3);
//	}
	cout<<num_of_path;	
	return 0;
}
