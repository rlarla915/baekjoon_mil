#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;


int main()
{
	unsigned long num_case, max_num = 5, num;
	scanf("%lu", &num_case);
	unsigned long dp[102] = {0};
	dp[1] = 1;
	dp[2] =1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	for (unsigned long i = 0; i< num_case ; i++)
	{
		scanf("%lu", &num);
		if (max_num < num)
		{
			for (unsigned long j = max_num+1; j <= num; j++)
			{
				dp[j] = dp[j-1] + dp[j-5];
				
			}
			max_num = num;
		}
		cout<<dp[num]<<endl;

	}

	return 0;
}