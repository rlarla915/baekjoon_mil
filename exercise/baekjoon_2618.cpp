#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

int distance(int * a, int * b)
{
	int tmp_x = a[0];
	tmp_x = tmp_x - b[0];
	if (tmp_x <0)
		tmp_x = tmp_x *-1;
	int tmp_y = a[1];
	tmp_y = tmp_y - b[1];
	if (tmp_y <0)
		tmp_y = tmp_y *-1;
	return tmp_x + tmp_y;
	
};

int main()
{
	int num_pix, num_case;
	scanf("%d", &num_pix);
	scanf("%d", &num_case);
	int cases[1001][2];
	for(int c = 1; c<= num_case; c++)
	{
		scanf("%d", &cases[c][0]);
		scanf("%d", &cases[c][1]);
	}
	int last_1[1001] = {0};
	int last_2[1001] = {0};
	int tmp_last_1[1001] = {0};
	int tmp_last_2[1001] = {0};
	int ** history_1 = new int *[1001];
	int ** history_2 = new int *[1001];
	for (int i = 0; i<=1000; i++)
	{
		history_1[i] = new int [1001];
		history_2[i] = new int [1001];
	}
	int tmp1[2] = {1, 1};
	int tmp2[2] = {num_pix, num_pix};
	last_1[0] = distance(tmp1, cases[1]);
	last_2[0] = distance(tmp2, cases[1]);
	history_1[0][1] = 1;
	history_2[0][1] = 2;
	if(num_case != 1)
	{
		for(int i = 2; i <= num_case; i++)
		{
			for (int p = 0 ; p < i-1; p++)
			{
				tmp_last_1[p] = last_1[p];
				tmp_last_2[p] = last_2[p];
			}
			int min_1 = last_2[0] + distance(tmp1, cases[i]), min_2 = last_1[0] + distance(tmp2, cases[i]), save_1 = 0, save_2 = 0;
			last_1[0] += distance(cases[i-1], cases[i]);
			last_2[0] += distance(cases[i-1], cases[i]);
			history_1[0][i] = 1;
			history_2[0][i] = 2;
			for (int j = 1; j<i-1 ; j++)
			{
				last_1[j] += distance(cases[i-1], cases[i]);
				last_2[j] += distance(cases[i-1], cases[i]);
				history_1[j][i] = 1;
				history_2[j][i] = 2;
				if (min_1 > tmp_last_2[j]+ distance(cases[j], cases[i]))
				{
					min_1 = tmp_last_2[j] + distance(cases[j], cases[i]);
					save_1 = j;
				}

				if (min_2 > tmp_last_1[j] + distance(cases[j], cases[i]))
				{
					min_2 = tmp_last_1[j] + distance(cases[j], cases[i]);
					save_2 = j;
				}

			}
			last_1[i-1] = min_1;
			last_2[i-1] = min_2;
			for (int k = 1 ; k<i; k++)
			{
				history_1[i-1][k] = history_2[save_1][k];
				history_2[i-1][k] = history_1[save_2][k];
			}
			history_1[i-1][i] =1;
			history_2[i-1][i] =2;
		}
		int min_1 = 2147483646, min_2 = 2147483646;
		int save_1, save_2;
		for (int i = 0; i<num_case ; i++)
		{
			if (last_1[i] < min_1)
			{
				min_1 = last_1[i];
				save_1 = i;
			}
			if (last_2[i] < min_2)
			{
				min_2 = last_2[i];
				save_2 = i;
			}
		}

		if (min_1 > min_2)
		{
			cout<<min_2<<"\n";
			for (int i = 1; i<= num_case; i++)
			{
				cout<<history_2[save_2][i]<<"\n";
			}
		}
		else
		{
			cout<<min_1<<"\n";
			for (int i = 1; i<= num_case; i++)
			{
				cout<<history_1[save_1][i]<<"\n";
			}
		}
	}
	else
	{
		if(distance(tmp1, cases[1]) > distance(tmp2, cases[1]))
		{
			cout<< distance(tmp2, cases[1])<<"\n"<<"2";
		}
		else{
			cout<< distance(tmp1, cases[1])<<"\n"<<"1";
		}
	}
	
	return 0;
}