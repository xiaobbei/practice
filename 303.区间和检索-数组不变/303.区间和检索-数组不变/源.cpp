#include<iostream>
#include<vector>

using namespace std;


/*��Ŀ����
����һ����������  nums�������������� i �� j  (i �� j) ��Χ��Ԫ�ص��ܺͣ����� i,  j ���㡣
���� nums = [-2, 0, 3, -5, 2, -1]����ͺ���Ϊ sumRange()

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3


*/

/*��̬�滮

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

//����NxN�ı��д���i���д���j��
/*dp[i][j]��ʾ��������iԪ�ص�jԪ�صĺ͡�
��һ�д���dp[0][j]��ʾ�������һ��Ԫ�ؼӵ�jԪ�ء�
�����Ͻǵ����½ǻ�һ���Խ��ߣ�i = j�����Խ���dp[i][j] = nums[j];
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