#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;


int main()
{
	int num_case, num;
	
	int n[501][501];
	int dp[501][501];
	
	scanf("%d", &num_case);
	for (int t = 0; t< num_case ; t++)
	{
		scanf("%d", &num);
		for(int i = 1; i <= num; i++)
		{
			scanf("%d", &dp[1][i]);
			n[1][i] = dp[1][i];
		}
		for(int i = 1; i < num; i++)
		{
			dp[2][i] = dp[1][i] + dp[1][i+1];
			n[2][i] = dp[2][i];
		}
		for (int i = 3; i <= num; i++)
		{
			for (int j = 1; j <= num-i+1; j++)
			{
				n[i][j] = n[i-1][j] + n[1][i+j-1];
			}
		}
		for (int i = 3; i <= num; i++)
		{
			for (int j = 1; j <= num-i+1; j++)
			{
				dp[i][j] = n[i][j];
				int min = 2100000000;
				for (int k = 1; k < i; k++)
				{
					if (k == 1)
					{
						if (min > dp[i-1][j+1])
							min = dp[i-1][j+1];
					}
					else if (k == i-1)
					{
						if (min > dp[i-1][j])
							min = dp[i-1][j];
					}
					else
					{
						if (min > dp[k][j] + dp[i-k][j+k])
							min = dp[k][j] + dp[i-k][j+k];
					}
				}
				dp[i][j] += min;
			}
		}
		cout<<dp[num][1]<<endl;
	}
	return 0;
}