//#include<iostream>
//#include<algorithm>

//using namespace std;
//int getLuckPacket(int x[], int n, int pos, int sum, int multi) {
//	int count = 0;
//	//ѭ����������λ��i��ʼ�����п������
//	for (int i = pos; i < n; ++i) {
//		sum += x[i];
//		multi *= x[i];
//		if (sum > multi) {
//			//�ҵ���iλ�ÿ�ʼ��������ϵĿ���
//			count += 1 + getLuckPacket(x, n, i + 1, sum, multi);
//		}
//		else if (x[i] == 1) {
//			//���������Ҫ���ҵ�ǰԪ��Ϊ 1
//			//������ܻ����ɻ󣬼�Ȼ������Ϊ�β�ֱ��break,���Ǽ���
//			//��Ϊ�� 1 ֮����ܻᵼ��������������
//			//���� 1 1 2 5 1 ��������һ��Ϊ 1����� 1֮����������
//			count += getLuckPacket(x, n, i + 1, sum, multi);
//		}
//		else {
//			//��Ϊ�Ѿ�����������������������һλ����1 ����ô������Զ����������
//			//ֱ���˳�
//			break;
//		}
//		//Ҫ������һ��λ��֮ǰ���Ȼָ� sum �� multi
//		sum -= x[i];
//		multi /= x[i];
//		//������ͬ����û���κ����𣬶�ֻ����һ����ϣ�����ֱ������
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
//		//�ӵ�һ��λ�ÿ�ʼ����
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