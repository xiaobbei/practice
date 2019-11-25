#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//int main()
//{
//	string s1, s2;
//	string Shortstr;
//	string Longstr;
//	while (cin >> s1 >> s2)
//	{
//		int flag = 0;
//		if (s1.size()>s2.size())
//		{
//			for (int i = 0; i<s1.size() - s2.size(); ++i)
//			{
//				Shortstr += '0';
//			}
//			Shortstr += s2;
//			Longstr = s1;
//		}
//		else
//		{
//			for (int i = 0; i<s2.size() - s1.size(); ++i)
//			{
//				Shortstr += '0';
//			}
//			Shortstr += s1;
//			Longstr = s2;
//		}
//		for (int i = Longstr.size() - 1; i >= 0; --i)
//		{
//			int temp = Longstr[i] - '0' + Shortstr[i] - '0' + flag;
//			if (temp >= 10)
//			{
//				flag = 1;
//				Longstr[i] = temp % 10 + '0';
//			}
//			else
//			{
//				flag = 0;
//				Longstr[i] = temp + '0';
//			}
//		}
//		if (flag == 1)
//		{
//			string a = "1";
//			Longstr = a + Longstr;
//		}
//		cout << Longstr << endl;
//		Longstr.clear();
//		Shortstr.clear();
//	}
//	system("pause");
//	return 0;
//}



int main()
{
	string a, b, result;
	int carry = 0;
	while (cin >> a >> b)
	{
		const size_t n = a.size() > b.size() ? a.size() : b.size();
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		for (size_t i = 0; i < n; i++)
		{
			const int ai = i < a.size() ? a[i] - '0' : 0;
			const int bi = i < b.size() ? b[i] - '0' : 0;
			const int val = (ai + bi + carry) % 10;
			carry = (ai + bi + carry) / 10;
			result.insert(result.begin(), val + '0');
		}
		if (carry == 1)
			result.insert(result.begin(), '1');
		cout << result << endl;
		result.clear();
		carry = 0;
	}
	return 0;
}