#include <iostream>
#include <cstdio>
#include <string>


using namespace std;


int main(){
	string country[4];
	double expect[3][4][4];
	for (int i = 0; i< 4; i++)
	{
		cin>> country[i];
	}
	for(int i = 0; i<6; i++)
	{
		int tmp_a, tmp_b;
		string coun_a, coun_b;
		cin>>coun_a;
		cin>>coun_b;
		for(int j = 0; j<4; j++)
		{
			if(coun_a == country[j])
			{
				tmp_a = j;
			}
			if(coun_b == country[j])
			{
				tmp_b = j;
			}
		}
		cin>>expect[0][tmp_a][tmp_b];
		expect[2][tmp_b][tmp_a] = expect[0][tmp_a][tmp_b];
		cin>>expect[1][tmp_a][tmp_b];
		expect[1][tmp_b][tmp_a] = expect[1][tmp_a][tmp_b];
		cin>>expect[2][tmp_a][tmp_b];
		expect[0][tmp_b][tmp_a] = expect[2][tmp_a][tmp_b];
		//cout<<"A: "<<tmp_a<<" ,B: "<<tmp_b<<" "<<expect[0][tmp_a][tmp_b]<<" "<<expect[1][tmp_a][tmp_b]<<" "<<expect[2][tmp_a][tmp_b]<<endl;
	}
	//cout<<"aa"<<endl;
	//float rate[3][3][3][3][3][3];
	double answer[4] = {0};
	
	for (int a = 0; a<3; a++)
	{
		for (int b = 0 ; b<3; b++)
		{
			for (int c = 0; c<3; c++)
			{
				for(int d = 0; d<3; d++)
				{
					for (int e = 0; e<3; e++)
					{
						for(int f = 0; f<3; f++)
						{
							//cout<<"bb"<<endl;
							int score[4] = {0};
							double rate = expect[a][0][1] * expect[b][0][2] * expect[c][0][3] * expect[d][1][2] * expect[e][1][3] * expect[f][2][3];
							if(a == 0)
							{
								score[0] +=3;
							}
							else if (a == 1)
							{
								score[0] +=1;
								score[1] +=1;
							}
							else
							{
								score[1] += 3;
							}
							
							if(b == 0)
							{
								score[0] +=3;
							}
							else if (b == 1)
							{
								score[0] +=1;
								score[2] +=1;
							}
							else
							{
								score[2] += 3;
							}
							
							if(c == 0)
							{
								score[0] +=3;
							}
							else if (c == 1)
							{
								score[0] +=1;
								score[3] +=1;
							}
							else
							{
								score[3] += 3;
							}
							
							if(d == 0)
							{
								score[1] +=3;
							}
							else if (d == 1)
							{
								score[1] +=1;
								score[2] +=1;
							}
							else
							{
								score[2] += 3;
							}
							
							if(e == 0)
							{
								score[1] +=3;
							}
							else if (e == 1)
							{
								score[1] +=1;
								score[3] +=1;
							}
							else
							{
								score[3] += 3;
							}
							
							if(f == 0)
							{
								score[2] +=3;
							}
							else if (f == 1)
							{
								score[2] +=1;
								score[3] +=1;
							}
							else
							{
								score[3] += 3;
							}
							//cout<<"cc"<<endl;
							int aaa[11] = {0};
							//cout<<"ddd"<<endl;
							for (int q = 0; q < 4; q++)
							{
								//cout<<score[q]<<endl;
								aaa[score[q]] = aaa[score[q]] + 1 ;
							}
							int tmp_1, tmp_2;
							bool check = true;
							for(int i = 9; i>=0; i--)
							{
								if(!check)
								{
									if(aaa[i] != 0)
									{
										tmp_2 = i;
										//cout<<"2nd : "<<tmp_2<<endl;
										//cout<<"2nd is "<<aaa[i]<<endl;
										break;
									}
								}
								else
								{
									if(aaa[i] != 0)
									{
										tmp_1 = i;
										//cout<<"1st : "<<tmp_1<<endl;
										//cout<<"1st is "<<aaa[i]<<endl;
										check = false;
									}
								}
								
							}
							if(aaa[tmp_1] >= 2)
							{
								for(int i = 0; i< 4; i++)
								{
									if(tmp_1 == score[i])
									{
										answer[i] += ((double)2)/aaa[tmp_1] * rate;
									}
								}
							}
							else
							{
								for (int i = 0; i<4; i++)
								{
									if(tmp_1 == score[i])
									{
										answer[i] += rate;
									}
									if(tmp_2 == score[i])
									{
										answer[i] += ((double)1)/aaa[tmp_2] * rate;
									}
								}
							}
							
						
						}
					}
				}
			}
		}
	}
	for(int i = 0; i< 4; i++)
	{
		cout<<fixed;
		cout.precision(15);
		cout<<answer[i]<<endl;
	}
	
	return 0;
}