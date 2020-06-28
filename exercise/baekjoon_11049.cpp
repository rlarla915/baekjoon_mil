#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;


int main()
{
	int num_case;
	int dp[501][501];
	int data[501][2];
	scanf("%d", &num_case);
	for (int i = 0 ; i <=500 ; i++)
	{
		for (int j = 0 ; j <=500 ; j++)
		{
			dp[i][j] = 0;
		}
	}
	for(int i = 0; i< num_case ; i++)
	{
		scanf("%d", &data[i][0]);
		scanf("%d", &data[i][1]);
	}
	for (int i = 0; i< num_case-1 ; i++)
	{
		dp[i][i+1] = data[i][0] * data[i+1][0] * data[i+1][1];
	}
	for(int i = 2; i< num_case ; i++)
	{
		for (int j = 0; j< num_case -i ; j++)
		{ 
			int min = 2147483647;
		
			for (int k = 1 ; k <= i ; k++)
			{
				int tmp;
				if (k == 1)
				{
					tmp = data[j][0] * data[j][1] * data[j+i][1] + dp[j+1][j+i];
				}
				else if (k == i)
				{
					tmp = data[j][0] * data[j+i][0] * data[j+i][1] + dp[j][j+i-1];
				}
				else
				{
					tmp = dp[j+k][j+i] + dp[j][j+k-1] + data[j][0] * data[j+k-1][1] * data[j+i][1];
				}
				
				if (min > tmp)
					min = tmp;
			}
			dp[j][j+i] = min;
		}
	}
	cout<<dp[0][num_case-1]<<endl;
	
	return 0;
}