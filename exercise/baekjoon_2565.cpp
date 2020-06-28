#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;


int main()
{
	int num_line;
	scanf("%d", &num_line);
	int dp[501] = {0};
	int line[501] = {0};
	int data_line[501] = {0};
	int tmp_1, tmp_2;
	for (int i = 0; i < num_line ; i++)
	{
		scanf("%d", &tmp_1);
		scanf("%d", &tmp_2);
		line[tmp_1] = tmp_2;
	}
	int index = 0;
	for (int i = 0; i <= 500; i++)
	{
		if(line[i] != 0 )
		{
			data_line[index] = line[i];
			index++;
		}
	}
	dp[0] =1;
	for(int i = 1; i < num_line; i++)
	{
		for (int j = 0 ; j < i ; j++)
		{
			if (data_line[i] > data_line[j] && dp[i] < dp[j])
				dp[i] = dp[j];
		}
		dp[i]++;
	}
	int max = 0; 
	
	for (int i = 0; i < num_line ; i++)
	{
		if (dp[i] > max)
		{
			max = dp[i];
		}
	}
	
	cout<< num_line - max;
	
	return 0;
}