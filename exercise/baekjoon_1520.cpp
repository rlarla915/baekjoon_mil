#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

class pixel{
public:
	int num, x, y;
	pixel()
	{
		
	}
	pixel(int a, int b, int c)
	{
		this->num = a;
		this->x = b;
		this->y = c;
	}
	bool operator < (pixel &pix)
	{
		return this->num > pix.num;
	}
};

/*
void merge(int pixel[250001], int a, int mid, int b)
{
	int count_a = a;
	int count_b = mid +1 ;
	int ** tmp = new int*[250001];
	for (int i = 0; i< 250001; i++)
	{
		tmp[i] = new int[3];
	}
	for (int i = a; i <= b ; i++)
	{
		if(count_a > mid)
		{
			for (int k = 0; k < 3; k++)
			{
				tmp[i][k] = A[count_b][k];
			}
			count_b++;
		}
		else if (count_b > b)
		{
			for (int k = 0; k < 3; k++)
			{
				tmp[i][k] = A[count_a][k];
			}
			count_a++;
		}
		else
		{
			if (A[count_a][0] <= A[count_b][0])
			{
				for (int k = 0; k < 3; k++)
				{
					tmp[i][k] = A[count_b][k];
				}
				count_b++;
			}
			else
			{
				for (int k = 0; k < 3; k++)
				{
					A[i][k] = A[count_a][k];
				}
				count_a++;
			}
		}
	}
	for(int i = a; i<=b;i++)
	{
		for (int k = 0; k < 3; k++)
		{
			A[i][k] = tmp[i][k];
		}
	}
}

void mergesort(int A[250001][3], int a, int b)
{
	int mid = int((a+b)/2);
	mergesort(A, a, mid);
	mergesort(A, mid+1, b);
	merge(A, a, mid, b);
}
*/

int main()
{
	int x, y;
	scanf("%d", &y);
	scanf("%d", &x);
	int map[501][501];
	int dp[501][501];
	pixel sorting[250001];
	int count = 0;
	for (int j = 0; j < y; j++)
	{
		for (int i = 0; i < x; i++)
		{
			scanf("%d", &map[i][j]);
			sorting[x*j+i] = pixel(map[i][j], i, j);
		}
	}
	sort(sorting, sorting + x*y-1);
	dp[0][0] = 1;
	for(int i = 0; i< x*y; i++)
	{
		if (sorting[i].x == 0)
		{
			if (map[sorting[i].x][sorting[i].y] < map[sorting[i].x + 1][sorting[i].y])
			{
				dp[sorting[i].x][sorting[i].y] += dp[sorting[i].x + 1][sorting[i].y];
			}
		}
		else if (sorting[i].x == x-1)
		{
			if (map[sorting[i].x][sorting[i].y] < map[sorting[i].x - 1][sorting[i].y])
			{
				dp[sorting[i].x][sorting[i].y] += dp[sorting[i].x - 1][sorting[i].y];
			}
		}
		else
		{
			if (map[sorting[i].x][sorting[i].y] < map[sorting[i].x + 1][sorting[i].y])
			{
				dp[sorting[i].x][sorting[i].y] += dp[sorting[i].x + 1][sorting[i].y];
			}
			if (map[sorting[i].x][sorting[i].y] < map[sorting[i].x - 1][sorting[i].y])
			{
				dp[sorting[i].x][sorting[i].y] += dp[sorting[i].x - 1][sorting[i].y];
			}
		}
		
		if (sorting[i].y == 0)
		{
			if (map[sorting[i].x][sorting[i].y] < map[sorting[i].x][sorting[i].y+1])
			{
				dp[sorting[i].x][sorting[i].y] += dp[sorting[i].x][sorting[i].y+1];
			}
		}
		else if (sorting[i].y == y-1)
		{
			if (map[sorting[i].x][sorting[i].y] < map[sorting[i].x][sorting[i].y-1])
			{
				dp[sorting[i].x][sorting[i].y] += dp[sorting[i].x][sorting[i].y-1];
			}
		}
		else
		{
			if (map[sorting[i].x][sorting[i].y] < map[sorting[i].x][sorting[i].y+1])
			{
				dp[sorting[i].x][sorting[i].y] += dp[sorting[i].x][sorting[i].y+1];
			}
			if (map[sorting[i].x][sorting[i].y] < map[sorting[i].x][sorting[i].y-1])
			{
				dp[sorting[i].x][sorting[i].y] += dp[sorting[i].x][sorting[i].y-1];
			}
		}
	}
	cout<<dp[x-1][y-1];
	return 0;
}