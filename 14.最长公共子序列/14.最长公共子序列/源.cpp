#include<iostream>
#include<string>
#include<vector>

using namespace std;

string longestCommonPrefix(vector<string> strs)
{
	if (strs.size() == 0)
		return "";
	string res = strs[0]; //�ȼ����һ���Ӵ�Ϊ�����Ӵ�
	for (int i = 1; i < strs.size(); ++i)
	{
		while (strs[i].find(res) != 0)//����������ַ����Ҳ���res����res�ĳ���-1
		{
			if (res == "")
				return "";
			res = res.substr(0, res.size() - 1);
		}
	}
	return res;
}

int main()
{
	vector<string> strs{ "flower", "flow", "flight" };
	cout<<longestCommonPrefix(strs);
	system("pause");
	return 0;
}