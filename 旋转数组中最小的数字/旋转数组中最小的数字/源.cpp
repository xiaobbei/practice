#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.empty() == 0)
		{
			return 0;
		}
		int temp = rotateArray[0];
		for (int i = 0; i < rotateArray.size() - 1; ++i)
		{
			if (temp > rotateArray[i])
			{
				temp = rotateArray[i];
			}
		}
		return temp;
	}
};
