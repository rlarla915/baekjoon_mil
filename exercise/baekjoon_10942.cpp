#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;


int main()
{
	int num_pix, num_case;
	
	scanf("%d", &num_pix);
	
	int pal[2001];
	int dp[2001][2001];
	
	for(int i= 0 ; i < num_pix ; i++)
	{
		scanf("%d", &pal[i]);
	}
	
	scanf("%d", &num_case);
	
	for (int i = 0; i <num_pix ; i++)
	{
		for (int j = 0; j<num_pix ; j++)
		{
			dp[i][j] = 0;
		}
	}

	
	for(int i= 0 ; i < num_pix ; i++)
	{
		for (int j = 0; j < num_pix - i ; j++)
		{
			if (i==0)
			{
				dp[j][0] = 1;
			}
			else if (i == 1)
			{
				if (pal[j] == pal[j+1])
				{
					dp[j][1] = 1;
				}
			}
			else
			{
				if(dp[j+1][i-2] == 1 && pal[j] == pal[j+i])
				{
					dp[j][i] = 1;
				}
			}
		}
	}
	
	
	
	for(int i = 0; i< num_case; i++)
	{
		int tmp_s, tmp_e;
		scanf("%d", &tmp_s);
		scanf("%d", &tmp_e);
		cout<<dp[tmp_s-1][tmp_e-tmp_s]<<"\n";
		
	}
	
	return 0;
}