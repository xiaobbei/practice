#include<iostream>
#include<vector>

using namespace std;
void oddInOddEvenInEven(vector<int>& arr, int len) {
	int start = 0;
	int end = 1;
	while (start < len && end < len)
	{
		while (start < len && (arr[start] % 2 == 0))
			start += 2;
		while (end < len && (arr[end] % 2 != 0))
			end+=2;
		if (start<len && end<len)
		swap(arr[start], arr[end]);
	}
}

int main()
{
	vector<int> res = { 1, 2, 3, 4 };
	oddInOddEvenInEven(res, 4);
	for (auto it : res)
		cout << it;
	system("pause");
	return 0;
}