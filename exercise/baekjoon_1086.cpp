
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <stdio.h>

using namespace std;

int num, divv;
long long dp[1<<15][100];
//int num_digit[1<<15];
string dataa[16];
int len_str[16];
int mod_all[651];
int mod_num[15];

long long gcd(long long a, long long b)
{
	long long tmp;
	if (a<b)
	{
		tmp = b;
		b = a;
		a = tmp;
	}
	while(a%b != (long long) 0)
	{
		tmp = b;
		b = a%b;
		a = tmp;
	}
	return b;
}

long long factorial(int n)
{
	if (n == 1)
	{
		return (long long)1;
	}
	else
	{
		return (long long)n * factorial(n-1);
	}
}

long long fun(int state, int modul)
{
	//cout<<"state : "<<state<<" mod : "<< modul<<" dp : "<<dp[state][modul]<<endl;
	if(dp[state][modul] != (long long)-1)
	{
		return dp[state][modul];
	}
	
	if (state == (1<<num)-1)
	{
		if(modul == 0)
		{
			return (long long) 1;
		}
		return (long long) 0;
	}
	long long tmp = (long long) 0;
	for (int i = 0; i< num; i++)
	{
		if(!(state & (1<<i)))
		{
			tmp += fun(state | (1<<i), (modul * mod_all[len_str[i]] + mod_num[i])%divv);
		}
	}
	dp[state][modul] = tmp;
	return tmp;
}


int main()
{
	scanf("%d", &num);
	for(int i = 0; i<(1<<num);i++)
	{
		for(int j = 0; j<100; j++)
		{
			dp[i][j] = (long long) -1;
		}
	}
	
	for (int i = 0; i< num ; i++)
	{
		cin>>dataa[i];
		len_str[i] = dataa[i].length();
	}
	scanf("%d", &divv);
	mod_all[0] = 1;
	for(int i = 1; i<=650; i++)
	{
		mod_all[i] = (mod_all[i-1]*10)%divv;
	}
	int tmp = 1;
	for (int i = 0; i<num; i++)
	{
		int tmp_len = len_str[i];
		int tmp_digit = 0;
		int tmp_mod = 0;
		
		while(tmp_len>9)
		{
			//cout<<"tmp_len : "<<tmp_len<<" , "<<atoi(dataa[i].substr(tmp_len-9, 9).c_str())<<endl;
			tmp_mod = (tmp_mod + (atoi(dataa[i].substr(tmp_len-9, 9).c_str())%divv)*mod_all[tmp_digit])%divv;
			tmp_digit +=9;
			tmp_len -= 9;
		}
		tmp_mod = (tmp_mod + (atoi(dataa[i].substr(0, tmp_len).c_str())%divv)*mod_all[tmp_digit])%divv;
		//cout<<tmp_mod<<endl;
		mod_num[i] = tmp_mod;
	}
	
	fun(0,0);
	if (dp[0][0] == (long long)0)
	{
		cout<<"0/1"<<endl;
	}
	else
	{
		long long tmp_gcd = gcd(dp[0][0], factorial(num));
		cout<<dp[0][0]/tmp_gcd<<"/"<<factorial(num)/tmp_gcd;
	}
	return 0;
}