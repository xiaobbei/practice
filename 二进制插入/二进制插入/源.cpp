#include<iostream>

using namespace std;

int binInsert(int n, int m, int j, int i) {
	return n | (m << j);
}
int main()
{
	cout << binInsert(1024, 19, 2, 6);
	system("pause");
	return 0;
}