#include <iostream>
#include <cstdio>
#include <string>
#include <stdio.h>


using namespace std;

int h[100002];

long long histo(int x, int y)
{
	if(x == y)
	{
		return h[x];
	}
	int half = (x+y)/2;
	long long max_sum = max(histo(x, half), histo(half +1, y));
	int a = half;
	int b = half+1;
	int least_h = min(h[a], h[b]);
	max_sum = max(max_sum, (long long)2*least_h);
	while(true)
	{
		if (a == x && b == y)
		{
			break;
		}
		else if (a == x)
		{
			least_h = min(least_h, h[b+1]);
			++b;
		}
		else if (b == y)
		{
			least_h = min(least_h, h[a-1]);
			--a;
		}
		else
		{
			if (h[a-1] > h[b+1])
			{
				least_h = min(least_h, h[a-1]);
				--a;
			}
			else
			{
				least_h = min(least_h, h[b+1]);
				++b;
			}
		}
		max_sum = max(max_sum, (long long) least_h * (b - a + 1));
	}
	return max_sum;
}

int main(){
	while(true)
	{
		int num_rect;
		scanf("%d", &num_rect);
		if (num_rect == 0)
		{
			break;
		}
		for(int i = 1; i <= num_rect; i++)
		{
			scanf("%d", &h[i]);
		}
		h[0] = 0;
		h[num_rect+1] = 0;
		cout<<histo(1, num_rect)<<"\n";
	}
	
	
	return 0;
}