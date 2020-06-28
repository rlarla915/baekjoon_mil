#include <iostream>
#include <cstdio>

using namespace std;


int main()
{
	int n, max = -200000000;
	scanf("%d", &n);
	int arr[100001] = {0};
	int dp[100001] = {0};
	for (int i = 0; i< n; i++)
	{
		scanf("%d", &arr[i]);
	}
	dp[0] = 0;
	for (int i = 1 ; i <= n; i++)
	{
		if (arr[i-1] >= 0)
		{
			if (dp[i-1] < 0)
			{
				dp[i] = arr[i-1];
			}
			else
			{
				dp[i] = arr[i-1] + dp[i-1];
			}
		}
		else if (dp[i-1] + arr[i-1] >= 0)
		{
			dp[i] = arr[i-1] + dp[i-1];
		}
		else
		{
			dp[i] = arr[i-1];
		}
		if (max < dp[i])
		{
			max = dp[i];
		}
	}
	cout << max <<endl;
	return 0;
}