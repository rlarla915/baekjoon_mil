#include <iostream>
#include <cstdio>

using namespace std;

long long get_gcd(long long tmp_a, long long tmp_b){
	
	long long a, c;
	
	if (tmp_a < tmp_b)
	{
		a = tmp_a;
		tmp_a = tmp_b;
		tmp_b = a;
	}
	
	while (tmp_b != 0)
	{
		c = tmp_a % tmp_b;
		tmp_a = tmp_b;
		tmp_b = c;
	}
	return tmp_a;
};


int main(){
	int num_line;
	bool check = false;
	long long tmp_money, rest_money, total_money, pre_rest, least_charge, gcd, least_rest;
	gcd = 0;
	pre_rest = 0;
	scanf("%d", &num_line);
	
	for (int i =0; i <num_line; i++)
	{
		scanf("%lld", &tmp_money);
		if (tmp_money > 0)
		{
			scanf("%lld", &rest_money);
			if(pre_rest + tmp_money != rest_money)
			{
				gcd = -1;
				break;
			}
		}
		else
		{
			scanf("%lld", &rest_money);
			if (pre_rest+tmp_money <0)
			{
				least_charge = rest_money - tmp_money - pre_rest;
				if (gcd == 0)
				{
					gcd = least_charge;
					least_rest = rest_money;
				}
				else
				{
					gcd = get_gcd(gcd, least_charge);
					if(rest_money > least_rest)
					{
						least_rest = rest_money;
					}
					if (least_rest >= gcd)
					{
						gcd = -1;
						break;
					}
				}
			}
			else
			{
				if (pre_rest + tmp_money != rest_money)
				{
					gcd = -1;
					break;
				}
			}
			
		}
	
		pre_rest = rest_money;
	}
	if (gcd == 0)
	{
		cout<< "1";
	}
	else
	{
		cout <<gcd;
	}
	
	return 0;
}