#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string>

using namespace std;

string pattern;
string str;
int pattern_length;
int string_length;
int num_case;
int dp[101][101];


int wildcard(int index_str, int index_pattern) 
{
	if (index_str >= string_length || index_pattern >= pattern_length)
	{
		return 0;
	}
	if (index_str == string_length - 1 && index_pattern == pattern_length - 1 && (pattern.at(index_pattern) == str.at(index_str) || pattern.at(index_pattern) == '*'))
	{
		return 1;
	}
	int& ret = dp[index_str][index_pattern];
	if (ret != -1)
	{
		return ret;
	}
	if (pattern.at(index_pattern) == '*')
	{
		ret = (wildcard(index_str+1, index_pattern) || wildcard(index_str, index_pattern+1));
	}
	else
	{
		if (pattern.at(index_pattern) != str.at(index_str))
		{
			ret = 0;
		}
		else
		{
			if (index_str == string_length - 1)
				ret = wildcard(index_str, index_pattern + 1);
			else
				ret = wildcard(index_str + 1, index_pattern + 1);
		}
	}
	return ret;
}


int main() {
	cin >> pattern;
	cin >> num_case;
	pattern_length = pattern.length();
	for (int i = 0; i < num_case; i++)
	{
		cin >> str;
		string_length = str.length();
		for (int a = 0; a <= 100; a++)
		{
			for (int b = 0; b <= 100; b++)
			{
				dp[a][b] = -1;
			}
		}
		if (wildcard(0, 0) == 1)
		{
			cout << str << endl;
		}
	}


}