#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;


int main()
{
	int dp[1001] = {0};
	int num;
	int n[1001] = {0};
	scanf("%d", &num);
	for (int i = 0; i< num ; i++)
	{
		scanf("%d", &n[i]);
	}
	dp[0] = 1;
	
	for (int i = 1; i < num ; i++)
	{
		int max = 0;
		for (int j = 0; j< i ; j++)
		{
			if(n[i] > n[j] && max < dp[j])
				max = dp[j];
		}
		dp[i] = max + 1;
	}
	int answer = 0;
	for (int i = 0; i< num ; i++)
	{
		if (answer < dp[i])
			answer = dp[i];
	}
	
	cout << answer;
	
	return 0;
}