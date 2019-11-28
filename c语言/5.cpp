#include<iostream>
#include<string>
using namespace std;

int main()
{
	int array[256] = {0};
	array['I'] = 1;
	array['V'] = 5;
	array['X'] = 10;
	array['L'] = 50;
	array['C'] = 100;
	array['D'] = 500;
	array['M'] = 1000;
	string s;
	while(cin>>s)
	{
		int sum = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (i + 1 <= s.size() && array[s[i + 1]] <= array[s[i]])
			{
				sum += array[s[i]];
			}
			else
				sum -= array[s[i]];
		}
		cout<<sum<<endl;
	}
	return 0;
 } 
