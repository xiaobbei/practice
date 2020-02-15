#include<iostream>
using namespace std

bool isIsomorphic(string s, string t) {
        int sc[128] = {0};
        int tc[128] = {0};
        int size = s.size();
        for(int i = 0; i<size; ++i) {
            sc[s[i]] += i+1;
            tc[t[i]] += i+1;
            if(sc[s[i]] != tc[t[i]])
                return false;
        }
        return true;
}

int main()
{
	return 0;
 } 
