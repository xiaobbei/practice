#include<iostream>
#include<vector>
using namespace std;
 void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        set<int> row, col;
        // �����ֱ�����к��е� set ���� row �� col
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j ++)
                if(matrix[i][j] == 0)
                {
                    row.insert(i);
                    col.insert(j);
                }
        // ���� set ������
        set<int>::iterator it;
        for(int i = 0; i < n; i ++)
            for(it = col.begin(); it != col.end(); it ++)
                matrix[i][*it] = 0;
        for(int i = 0; i < m; i ++)
            for(it = row.begin(); it != row.end(); it ++)
                matrix[*it][i] = 0;
    }

int main(){
 } 
