#include<iostream> 
#include<string>
#include<vector>
using namespace std;
void sortColors(vector<int>& nums) 
{
    int arrCache[3] = { 0 };
    for (auto const &pos : nums) {
        ++arrCache[pos];
    }
    int i = -1, j = -1;
    while (++i < 3) {
        while (arrCache[i]--) {
            nums[++j] = i;
        }
    }
}  
int main()
{
	
	return 0;
}
