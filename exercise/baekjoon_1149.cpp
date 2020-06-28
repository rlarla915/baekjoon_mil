#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;


int main()
{
	int num_house;
	int min_v = 10000000;
	scanf("%d", &num_house);
	
	int R[1001] = {0};
	int G[1001] = {0};
	int B[1001] = {0};
	int dp[3][1001];
	for (int i = 0; i< num_house; i++)
	{
		scanf("%d", &R[i]);
		scanf("%d", &G[i]);
		scanf("%d", &B[i]);
	}
	dp[0][0] = R[0];
	dp[1][0] = G[0];
	dp[2][0] = B[0];
	
	for (int i = 1; i< num_house; i++)
	{
		dp[0][i] = min(dp[1][i-1], dp[2][i-1]) + R[i];
		dp[1][i] = min(dp[0][i-1], dp[2][i-1]) + G[i];
		dp[2][i] = min(dp[0][i-1], dp[1][i-1]) + B[i];
	}
	for(int i = 0; i<3; i++)
	{
		if (min_v > dp[i][num_house-1])
		{
			min_v = dp[i][num_house-1];
		}
	}
	cout << min_v << endl;
	return 0;
}