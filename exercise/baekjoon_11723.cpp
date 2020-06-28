
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;


int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int set = 0;
	int num, tmp_num;
	cin >> num;
	string tmp;
	for(int i = 0 ; i< num ; i++)
	{
		cin>>tmp;
		if (tmp == "all")
		{
			set = (1<<21) -1;
		}
		else if (tmp == "empty")
		{
			set = 0;
		}
		else if (tmp == "add")
		{
			cin>>tmp_num;
			set |= (1<<tmp_num);
		}
		else if (tmp == "remove")
		{
			cin>>tmp_num;
			set &= ~(1<<tmp_num);
		}
		else if (tmp == "check")
		{
			cin>>tmp_num;
			cout<< ((set & (1<<tmp_num)) != 0)<<"\n";
		}
		else
		{
			cin>>tmp_num;
			set ^= (1<<tmp_num);
		}
		
			
	}
	
	return 0;
}