#include<iostream>

using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
        int length = cost.size();
        int _min = 0;
        if(length == 0 || length == 1)
            return _min;
        else if(length == 2)
            return cost[0]>cost[1]?cost[1]:cost[0];
        else 
        {
            vector<int> dp;
            dp.push_back(cost[0]);
            dp.push_back(cost[1]);
            for(int i = 2;i<length;++i)
            {
                dp.push_back(min(cost[i] + dp[i-1],cost[i] + dp[i-2]));
            }
            _min = min(dp[length-1],dp[length-2]);
            return _min;
        }
}

int main()
{
} 
