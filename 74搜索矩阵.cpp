#include<iostream> 
#include<string>
#include<vector>
using namespace std;
bool searchMatrix_1(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()||matrix[0].empty())return false;
        for(const auto& m:matrix)
        {
            if(find(m.begin(),m.end(),target)!=m.end())return true;
        }
        return false;
    }
int main()
{
	
	return 0;
}
