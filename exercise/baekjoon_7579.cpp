#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;


int main()
{
	int num_app, num_mem;
	scanf("%d", &num_app);
	scanf("%d", &num_mem);
	int cost[101];
	int mem[101];
	
	int **dp = new int *[101];
	for (int i = 0; i<101; i++)
	{
		dp[i] = new int[10001];
	}
	for(int i = 0; i<10001; i++)
	{
		dp[0][i] =0;
	}
	
	for (int i = 1; i <=num_app ; i++)
	{
		scanf("%d", &mem[i]);
	}
	for (int i = 1; i <=num_app ; i++)
	{
		scanf("%d", &cost[i]);
	}
	
	for (int i = 1; i<= num_app; i++)
	{
		for (int j = 0 ; j <= 10000 ; j++)
		{
			if (j-cost[i]<0)
			{
				dp[i][j] = dp[i-1][j];
			}
			else
			{
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i]]+mem[i]);
			}
		}
	}
	for(int i = 0; i<=10000; i++)
	{
		if(num_mem <= dp[num_app][i])
		{
			cout<<i<<endl;
			break;
		}
	}
	
	
	return 0;
}