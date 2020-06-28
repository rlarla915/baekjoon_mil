#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;


int main()
{
	int left[1001] = {0};
	int right[1001] = {0};
	int n;
	int num[1001] = {0};
	
	scanf("%d", &n);
	for (int i = 0; i< n; i++)
	{
		scanf("%d", &num[i]);
	}
	
	left[0] = 1;
	right[n-1] = 1;
	for (int i = 1; i< n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(num[j] < num[i] && left[i] < left[j])
			{
				left[i] = left[j];
			}
			if(num[n-1-j] < num[n-1-i] && right[n-1-i] < right[n-1-j])
			{
				right[n-1-i] = right[n-1-j];
			}
		}
		left[i]++;
		right[n-1-i]++;
	}
	int max = 0;
	for (int i = 0; i<n ; i++)
	{
		if (max < left[i] + right[i])
		{
			max = left[i] + right[i];
		}
	}
	
	cout<< max -1;
	
	return 0;
}