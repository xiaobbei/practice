#include<iostream>
#include<vector>
using  namespace std;
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    if(m == 0)
    {
        return 0;
    }
    int n = obstacleGrid[0].size();
    vector<vector<long long int>>dp(m + 1, vector<long long int>(n + 1, 0));
    dp[m][n - 1] = 1;
    for(int i = m - 1; i >= 0; i--){
        for(int j = n - 1; j >= 0; j--){
            if(obstacleGrid[i][j] == 0){
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }
    }
    return dp[0][0];
}


int main()
{
	return 0;
}
