#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;


class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int row = array.size();
		int col = array[0].size();
		assert(row > 0 && col > 0 && !array.empty());
		int rows = 0;
		int cols = col - 1;
		while (rows <= row && cols <= col)
		{
			if (target == array[rows][cols])
			{
				return true;
			}
			else if (target < array[rows][cols])
			{
				cols--;
			}
			else if (target > array[rows][cols])
			{
				rows++;
			}
		}
		return false;
	}
};
int main()
{

	system("pause");
	return 0;
}