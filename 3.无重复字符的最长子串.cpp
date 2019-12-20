#include<iostream>

#include<string>

using namespace std; 
int lengthOfLongestSubstring(string s) {
    int arr[256] = {0};
    int left = 0;
    int temp = 0,max = 0;
    for(int right = 0;right<s.size();++right)
    {
        if(arr[s[right]] == 0)
        {
            arr[s[right]] = right + 1;
            temp++;
        }
        else
        {
            left = left>arr[s[right]]?left:arr[s[right]];
            arr[s[right]] = right + 1;
            temp = right - left + 1; 
        }
        max = max>temp?max:temp;
    }
    return max;
} 

int main()
{
	string s;
	cin>>s;
	cout<<lengthOfLongestSubstring(s);
	return 0;
}
