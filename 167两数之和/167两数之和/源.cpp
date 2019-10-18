#include<iostream>
#include<vector>
using namespace std;


//双指针，从前后同时遍历，大于后--，小于前++
vector<int> twoSum(vector<int>& numbers, int target) {
	int left = 0;
	int right = numbers.size() - 1;
	while (left <right)
	{
		if (numbers[left] + numbers[right] == target)
			return{ left + 1,right + 1 };
		if (numbers[left] + numbers[right] > target)
			right--;
		if (numbers[left] + numbers[right] < target)
			left++;
	}
	return{ -1,-1 };
}


//二分法
vector<int> twoSum(vector<int>& numbers, int target)
{
	int i, l, r, m, flag = 0;
	for (i = 0; i < numbers.size() - 1; ++i)
	{
		l = i + 1;
		r = numbers.size() - 1;
		while (l <= r)
		{
			m = (l + r) / 2;
			if (numbers[m] > target - numbers[i])
				r = m - 1;
			else if (numbers[m] < target - numbers[i])
				l = m + 1;
			else if (numbers[m] == target - numbers[i])
			{
				flag = 1;
				break;
			}
		}
		if (flag)
			break;
	}
	vector<int> res;
	res[0] = i + 1;
	res[1] = m + 1;
	return res;
}


int main()
{
	system("pause");
	return 0;
}