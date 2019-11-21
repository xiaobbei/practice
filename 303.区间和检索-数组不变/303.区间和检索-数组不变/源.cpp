#include<iostream>
#include<vector>

using namespace std;


/*题目描述
给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。
给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3


*/

/*动态规划

class NumArray {
public:
	NumArray(vector<int>& nums) {
		int n = nums.size();
		if (n > 0)
		{
			vector<int> temp(n + 1);
			temp[0] = 0;
			for (int i = 1; i <= n; ++i)
			{
				temp[i] = temp[i - 1] + nums[i - 1];
			}
			res.swap(temp);
		}
	}
	int sumRange(int i, int j) {
		return res[j + 1] - res[i];
	}
private:
	vector<int> res;
};
int main()
{

	system("pause");
	return 0;
}
*/

//建立NxN的表，行代表i，列代表j。
/*dp[i][j]表示，从数组i元素到j元素的和。
第一行代表dp[0][j]表示从数组第一个元素加到j元素。
从左上角到右下角画一条对角线（i = j）。对角线dp[i][j] = nums[j];
*/


class NumArray {
public:
	NumArray(vector<int>& nums) {
		int n = nums.size();
		if (n > 0)
		{
			vector<vector<int>> temp(n);
			for (int i = 0; i < n; ++i)
			{
				temp[0].resize(n);
			}
			temp[0][0] = nums[0];
			for (int i = 1; i < n; ++i)
			{
				temp[0][i] = temp[0][i - 1] + nums[i];
				for (int j = 1; j <=i; ++j)
				{
					temp[j][i] = temp[j - 1][i] - nums[i - 1];
				}
 			}
			res.swap(temp);
		}
	}

	int sumRange(int i, int j) {

		return res[i][j];
	}
private:
	vector<vector<int>>res;
};
int main()
{

	system("pause");
	return 0;
}