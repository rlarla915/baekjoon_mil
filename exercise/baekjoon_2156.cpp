#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;


int main()
{
	int num;
	int n[10005] = {0};
	int a[10005] = {0}; //자신 앞에 있는 것을 마신 경우
	int b[10005] = {0}; //자신 앞에 있는 것을 마시지 않은 경우
	scanf("%d", &num);
	for (int i =0; i< num ; i++)
	{
		scanf("%d", &n[i]);
	}
	a[0] = n[0]; // 초기화 부분 n = 1 일떄 생각
	b[0] = n[0];
	a[1] = n[0] + n[1];
	b[1] = n[1];
	a[2] = n[1] + n[2];
	b[2] = n[0] + n[2];
	if (num == 1)
	{
		cout<<n[0];
	}
	else if (num == 2)
	{
		cout << n[0] + n[1];
	}
	else if (num == 3)
	{
		cout << max(max(n[0] + n[1] , n[0] + n[2]), n[1] + n[2]);
	}
	else
	{
		for (int i = 3 ; i< num ; i++)
		{
			a[i] = n[i] + b[i-1];
			b[i] = n[i] + max(max(a[i-3], a[i-2]), b[i-2]);
		}
		cout<< max(max(a[num-2], b[num-2]), max(a[num-1], b[num-1]));		
	}

	return 0;
}