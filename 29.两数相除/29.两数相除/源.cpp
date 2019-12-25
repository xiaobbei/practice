#include<iostream>

using namespace std;

int divide(int dividend, int divisor) {
	if (divisor == -1 && dividend == INT_MIN) return INT_MAX;
	if (divisor == 1 && dividend == INT_MIN) return INT_MIN;
	int sign = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0) ? -1 : 1;
	if (divisor == INT_MIN) return dividend == INT_MIN ? 1 : 0;
	divisor = abs(divisor);

	int res = 0;
	if (dividend == INT_MIN){
		res += 1;
		dividend += divisor;
	}

	dividend = abs(dividend);
	if (divisor  > dividend) return res*sign;
	while (dividend != 1 && dividend != 0 && dividend > divisor){
		int tmp = divisor; int cnt = 1;
		while (dividend > (tmp << 1)){
			if ((tmp << 1)  < tmp) break;
			tmp = tmp << 1;
			cnt = cnt << 1;
		}
		dividend -= tmp;
		res += cnt;
	}
	res = (res + (dividend < divisor ? 0 : 1)) * sign;
	return res;;
}
int main()
{
	system("pause");
	return 0;
}