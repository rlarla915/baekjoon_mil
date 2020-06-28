#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;


int main()
{
	int dp[1000001] = {0};
	
	
	int num;
	
	scanf("%d", &num);
	dp[0] = 1;
	dp[1] = 2;
	if (num < 3)
	{
		cout << dp[num-1];
	}
	else
	{
		for (int i = 2; i < num ; i++)
		{
			dp[i] = dp[i-1] + dp[i-2];
			if (dp[i] > 15746)
			{
				dp[i] = dp[i] % 15746;
			}
		}
		cout << dp[num-1];
	}
	return 0;
}