#include <iostream>
#include <cstdio>

using namespace std;


int main()
{
	int num_stuff;
	int weight;
	scanf("%d", &num_stuff);
	scanf("%d", &weight);
	int * value_arr = new int[num_stuff+1];
	int * weight_arr = new int[num_stuff+1];
	
	int **arr = new int*[num_stuff+1];
	for (int i = 0; i<num_stuff+1 ; i++)
	{
		arr[i] = new int[weight+1];
	}
	
	
	for (int i =0 ; i < num_stuff ; i++)
	{
		scanf("%d", &weight_arr[i]);
		scanf("%d", &value_arr[i]);
	}
	
	for (int i =0 ; i <= weight ; i++)
	{
		arr[0][i] = 0;
	}
	
	for (int i = 1 ; i <= num_stuff ; i++)
	{
		for (int j = 0 ; j <= weight ; j++)
		{
			if( j < weight_arr[i-1])
			{
				arr[i][j] = arr[i-1][j];
			}
			else if (arr[i-1][j] < (arr[i-1][j-weight_arr[i-1]]+value_arr[i-1]) )
			{
				arr[i][j] = arr[i-1][j-weight_arr[i-1]]+value_arr[i-1];
			}
			else
			{
				arr[i][j] = arr[i-1][j];
			}
		}
	}
	int max = 0;
	
	for (int i = 0; i <=weight ; i++)
	{
		if (max < arr[num_stuff][i])
		{
			max = arr[num_stuff][i];
		}
	}
	
	cout << max;
	
	return 0;
}