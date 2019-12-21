#include<iostream>
#include<string>
#include<string.h>
#include<limits.h>
using namespace std;

int myAtoi(string str)
{
	int res = 0;
        int i = 0;
        int flag = 1;
        while(i<str.size() && str[i]==' ')
            i++;
        if(str[i] == '-')
            flag = -1;
        if(str[i] == '+' || str[i] == '-')
            i++;
        if(!isdigit(str[i]))
        	return 0;
        while(i<str.size() && isdigit(str[i]))
        {
            int temp = str[i] - '0';
            if(res>INT_MAX/10 || (res == INT_MAX/10 && temp>7))
                return flag>0?INT_MAX:INT_MIN;
            res = res*10 + temp;
            i++;
        }
        return flag>0?res:-res;

}
int main()
{
	string s;
	while(cin>>s)
	{
		cout<<myAtoi(s);
	}
	return 0;
}
