#include <iostream>
#include <cstdio>

using namespace std;


int main()
{
	int value[10001] = {0};
	int coin[101];

	int num_coin, num_value;
	scanf("%d %d", &num_coin, &num_value);
	
	for (int i = 0; i<num_coin; i++)
	{
		scanf("%d", &coin[i]);
	}
	value[0] = 1;
	
	for(int i = 0; i<num_coin; i++)
	{
		for (int j = coin[i]; j<=num_value ; j++)
		{
			value[j] += value[j - coin[i]];
		}
	}
	
	cout << value[num_value] <<endl;
	
	return 0;
}