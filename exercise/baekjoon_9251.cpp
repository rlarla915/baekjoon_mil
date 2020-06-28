#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;


int main()
{
	string a, b;
	cin >> a >> b;
	int dp[1001][1001];
	for (int i = 0 ; i <= 1000 ; i++)
	{
		dp[0][i] = 0;
		dp[i][0] = 0;
	}
	int size_a = a.size();
	int size_b = b.size();
	
	for(int i = 1; i <= size_a ; i++)
	{
		for (int j = 1 ; j <= size_b ; j++)
		{
			dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
			if (a.at(i-1) == b.at(j-1))
			{
				dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
			}
		}
	}
	
	cout<< dp[size_a][size_b];
	
	return 0;
}