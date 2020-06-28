
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include<stdio.h>

using namespace std;

int dp[1001][1001];
int num, select_num;

int fun(int n, int r)
{
	if(dp[n][r] != -1)
	{
		return dp[n][r];
	}
	else{
		if(r==1)
		{
			dp[n][r] = n;
			return n;
		}
		if(int((n+1)/2) < r)
		{

			dp[n][r] = 0;
			return 0;
		}
		else
		{
			if(n == num)
			{
				dp[n][r] = fun(n-3, r-1)%1000000003 + fun(n-1, r)%1000000003;
			
			}
			else
			{
				dp[n][r] = fun(n-2, r-1)%1000000003 + fun(n-1, r)%1000000003;
			}
			dp[n][r] = dp[n][r] %1000000003;
			return dp[n][r];
		}
	}
}


int main()
{
	scanf("%d", &num);
	scanf("%d", &select_num);
	for(int i = 0; i<= num; i++)
	{
		for(int j = 0; j<= select_num; j++)
		{
			dp[i][j] = -1;
		}
	}

	cout<<fun(num, select_num);


	return 0;
}