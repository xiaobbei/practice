#include<iostream>
#include<vector>
using namespace std;

void reverseString(vector<char>& s) {
	if (s.empty())
		return;
	size_t left = 0;
	size_t right = s.size() - 1;
	char c;
	while (left<right)
	{
		c = s[left];
		s[left] = s[right];
		s[right] = c;
		left++;
		right--;
	}
}

int main()
{
	vector<char> s;
	s.push_back('h');
	s.push_back('e');
	s.push_back('l');
	s.push_back('l');
	s.push_back('o');
	reverseString(s);
	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it;
		it++;
	}
	system("pause");
	return 0;
}