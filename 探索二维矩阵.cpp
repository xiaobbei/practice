#include<iostream>
#include<vector>

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if ( !matrix.size()||!matrix[0].size() ) {
            return false;
        }
        int t = -1;
        for(int i = 0;i < matrix.size();i++)
        {
            if(target <= matrix[i][matrix[i].size() - 1])
            {
                 t = i;
                 break;
            }
        }
        if(t == -1)
        return false;
        else
        {
            int l = 0;
            int r = matrix[t].size() - 1;
            while(l < r)////¶þ·Ö
            {
                int mid = l + r >> 1;
                if(matrix[t][mid] >= target) r = mid;
                else l = mid + 1;
            }
            if(matrix[t][l] == target)
            return true;
            else
            return false;
        }
    }
int main()
{
 } 
