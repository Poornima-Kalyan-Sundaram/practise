#include<iostream>
using namespace std;
int main()
{
	int a[10];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	cin >> a[i];

	int i = 0, j = 1, temp;
	while (i < n - 1)
	{
		j = i + 1;
		temp = a[j];
		while (j >= 1 )
		{
		if(a[j-1]>temp)
		a[j] = a[j - 1];
		j--;
		}
		a[j] = temp;
		i++;
	}

}

