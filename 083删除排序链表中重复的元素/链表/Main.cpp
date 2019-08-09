#include"List.h"

int main()
{
	NodeList  *N;
	N = Init();
	N = Push(N, 3);
	N = Push(N, 3);
	N = Push(N, 2);
	N = Push(N, 1);
	N = Push(N, 1);
	N = Push(N, 1);
	N = Push(N, 1);
	N = Push(N, 1);
	deleteDuplicates(N);
	NodePri(N);
	system("pause");
	return 0;
}

