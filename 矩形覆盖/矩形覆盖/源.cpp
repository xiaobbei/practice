#include<iostream>

using namespace std;

int rectCover(int number) {
	int rect1 = 1;
	int rect2 = 2;
	int temp = 0;
	for (int i = 3; i <= number; ++i)
	{
		temp = rect1 + rect2;
		rect1 = rect2;
		rect2 = temp;
	}
	return rect2;
}
int main()
{
	cout<< rectCover(3);
	system("pause");
	return 0;
}