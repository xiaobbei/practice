#include<iostream>

using  namespace std;
int uniquePaths(int m, int n){
	if(m <= 0 || n <= 0)
		return 0;
	else if(m == 1  || n == 1)//只能一直向右走或者一直向下走，所以路径数为 1
		return 1;
	else if(m == 2 && n == 2)
		return 2;
	else if((m == 3 && n == 2) || (m == 2 && n == 3))
		return 3;
	int paths = 0;
	paths += uniquePaths(m-1,n);
	paths += uniquePaths(m,n-1);
	return paths;
}

int main()
{
	return 0;
}
