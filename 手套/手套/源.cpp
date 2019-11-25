#include<iostream>
#include<vector>
using namespace std;

int Min(int a, int b)
{
	return a > b ? b : a;
}


int FindMin(int n, vector<int> left, vector<int> right)
{
	int min = 0;
	int left_sum = 0;
	int right_sum = 0;
	int left_min = 27;
	int right_min = 27;
	for (int i = 0; i < n; ++i)
	{
		if (left[i] * right[i] == 0)
			min += left[i] + right[i];
		else
		{
			left_sum += left[i];
			right_sum += right[i];
			left_min = Min(left_min, left[i]);
			right_min = Min(right_min, right[i]);
		}
	}
	return min + Min(left_sum - left_min + 1, right_sum - right_min + 1) + 1;
}
int main()
{
	vector<int> left{ 0, 7 };
	vector<int> right{ 1, 5};
	cout << FindMin(2, left, right);
	system("pause");
	return 0;
}