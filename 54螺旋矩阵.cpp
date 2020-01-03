#include<iostream>
#include<vector>

using namespace std; 
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector <int> ans;
    if(matrix.empty()) return ans; //������Ϊ�գ�ֱ�ӷ��ش�
    int u = 0; //��ֵ�������ұ߽�
    int d = matrix.size() - 1;
    int l = 0;
    int r = matrix[0].size() - 1;
    while(true)
    {
        for(int i = l; i <= r; ++i) ans.push_back(matrix[u][i]); //�����ƶ�ֱ������
        if(++ u > d) break; //�����趨�ϱ߽磬���ϱ߽�����±߽磬�����������ɣ���ͬ
        for(int i = u; i <= d; ++i) ans.push_back(matrix[i][r]); //����
        if(-- r < l) break; //�����趨�б߽�
        for(int i = r; i >= l; --i) ans.push_back(matrix[d][i]); //����
        if(-- d < u) break; //�����趨�±߽�
        for(int i = d; i >= u; --i) ans.push_back(matrix[i][l]); //����
        if(++ l > r) break; //�����趨��߽�
    }
    return ans;
}


int main()
{
	
	return 0;
}

