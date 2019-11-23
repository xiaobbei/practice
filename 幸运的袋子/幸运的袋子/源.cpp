//#include<iostream>
//#include<algorithm>

//using namespace std;
//int getLuckPacket(int x[], int n, int pos, int sum, int multi) {
//	int count = 0;
//	//循环，搜索以位置i开始的所有可能组合
//	for (int i = pos; i < n; ++i) {
//		sum += x[i];
//		multi *= x[i];
//		if (sum > multi) {
//			//找到以i位置开始的所有组合的可能
//			count += 1 + getLuckPacket(x, n, i + 1, sum, multi);
//		}
//		else if (x[i] == 1) {
//			//如果不符合要求，且当前元素为 1
//			//这里可能会有疑惑，既然不满足为何不直接break,而是继续
//			//因为加 1 之后可能会导致条件继续成立
//			//例如 1 1 2 5 1 如果这个下一个为 1，则加 1之后条件成立
//			count += getLuckPacket(x, n, i + 1, sum, multi);
//		}
//		else {
//			//因为已经对数组进行升序，所以如果下一位不是1 ，那么条件永远不可能满足
//			//直接退出
//			break;
//		}
//		//要搜索下一个位置之前，先恢复 sum 和 multi
//		sum -= x[i];
//		multi /= x[i];
//		//数字相同的球没有任何区别，都只能算一个组合，所以直接跳过
//		while (i < n - 1 && x[i] == x[i + 1]) {
//			i++;
//		}
//	}
//	return count;
//}
//int main() {
//	int n;
//	while (cin >> n) {
//		int x[10000] = { 0 };
//		for (int i = 0; i < n; ++i) {
//			cin >> x[i];
//		}
//		sort(x, x+n);
//		//从第一个位置开始搜索
//		cout << getLuckPacket(x, n, 0, 0, 1) << endl;
//	}
//	return 0;
//}



#include<iostream>
#include<algorithm>

using namespace std;

int GetLuckCount(int array[], int n, int pos, int sum, int multi)
{
	int count = 0;
	for (int i = pos; i<n; ++i)
	{
		sum += array[pos];
		multi *= array[pos];
		if (sum>multi)
		{
			count += GetLuckCount(array, n, i + 1, sum, multi) + 1;
		}
		else if (array[i] == 1)
		{
			count += GetLuckCount(array, n, i + 1, sum, multi);
		}
		else
		{
			break;
		}
		sum -= array[i];
		multi /= array[i];
		while (i<n - 1 && array[i] == array[i + 1])
			i++;
	}
	return count;
}
int main()
{
	int array[1000] = { 0 };
	int n;
	while (cin >> n)
	{
		for (int i = 0; i<n; ++i)
		{
			cin >> array[i];
		}
		sort(array, array + n);
		cout << GetLuckCount(array, n, 0, 0, 1);
	}
	system("pause");
	return 0;
}