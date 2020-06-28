
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include<stdio.h>

using namespace std;

int num_town;
int cost[16][16];
int ** dp;

int tsp(int current, int state)
{
	if (dp[current][state] != 0)
	{
		return dp[current][state];
	}
	if (state == (1 << num_town)-1)
	{

		if (cost[current][0] > 0)
		{
			return cost[current][0];
		}
		return 987654321;
	}
	int min = 987654321, tmp;
	for (int i = 0; i < 16 ; i++)
	{
		if (!(state &(1<<i))&& cost[current][i] != 0)
		{
			tmp = tsp(i, state | (1<<i)) + cost[current][i];
			if (min > tmp)
			{
				min = tmp;
			}
		}
	}
	dp[current][state] = min;
	return min;
}

int main()
{
	scanf("%d", &num_town);
	dp = new int *[num_town];
	for(int i = 0 ; i< num_town ; i++)
	{
		dp[i] = new int[1<<num_town];
		for (int j = 0; j<(1<<num_town); j++)
		{
			dp[i][j] = 0;
		}
	}
	
	for(int i = 0 ; i< num_town ; i++)
	{
		for (int j = 0; j<num_town ; j++)
		{
			scanf("%d", &cost[i][j]);
		}
	}
	tsp(0, 1);
	cout<<dp[0][1];
	
	
	return 0;
}