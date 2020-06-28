
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include<stdio.h>

using namespace std;



int main()
{
	int num;
	scanf("%d", &num);
	int r[1001][3];
	int g[1001][3];
	int b[1001][3];
	for (int i = 0; i< num; i++)
	{
		r[i][0] = 987654321;
		r[i][1] = 987654321;
		r[i][2] = 987654321;
		g[i][0] = 987654321;
		g[i][1] = 987654321;
		g[i][2] = 987654321;
		b[i][0] = 987654321;
		b[i][1] = 987654321;
		b[i][2] = 987654321;
	}
	int data[1001][3];
	for(int i = 0; i< num; i++)
	{
		scanf("%d", &data[i][0]);
		scanf("%d", &data[i][1]);
		scanf("%d", &data[i][2]);
	}
	r[0][0] = data[0][0];
	g[0][1] = data[0][1];
	b[0][2] = data[0][2];
	
	for(int i = 1; i< num ; i++)
	{
		for(int j = 0; j<3; j++)
		{
			if (min(g[i-1][j], b[i-1][j]) == 987654321)
			{
				r[i][j] = 987654321;
			}
			else
			{
				r[i][j] = min(g[i-1][j], b[i-1][j]) + data[i][0];
			}
			if (min(r[i-1][j], b[i-1][j]) == 987654321)
			{
				g[i][j] = 987654321;
			}
			else
			{
				g[i][j] = min(r[i-1][j], b[i-1][j]) + data[i][1];
			}
			if (min(r[i-1][j], g[i-1][j]) == 987654321)
			{
				b[i][j] = 987654321;
			}
			else
			{
				b[i][j] = min(r[i-1][j], g[i-1][j]) + data[i][2];
			}
		}
	}
	int min = 987654321;
	if(r[num-1][1] < min)
		min = r[num-1][1];
	if(r[num-1][2] < min)
		min = r[num-1][2];
	if(g[num-1][0] < min)
		min = g[num-1][0];
	if(g[num-1][2] < min)
		min = g[num-1][2];
	if(b[num-1][0] < min)
		min = b[num-1][0];
	if(b[num-1][1] < min)
		min = b[num-1][1];
	cout<<min;
	return 0;
}