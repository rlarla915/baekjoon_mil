#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;


int main()
{
	int dp_0[41] = {0};
	int dp_1[41] = {0};
	dp_0[0] = 1;
	dp_1[0] = 0;
	dp_0[1] = 0;
	dp_1[1] = 1;
	
	int num_case, num, max = 1;
	scanf("%d", &num_case);
	for (int i = 0; i< num_case ;  i++)
	{
		scanf("%d", &num);
		if (max < num)
		{
			for (int j = max+1; j <= num ; j++)
			{
				dp_0[j] = dp_0[j-1] + dp_0[j-2];
				dp_1[j] = dp_1[j-1] + dp_1[j-2];
			}
			max = num;
		}
		cout << dp_0[num] << " " << dp_1[num]<<endl;
	}
	
	return 0;
}