#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int>v;
	int Hi, Mi;
	for (int i = 0; i < N; ++i)
	{
		cin >> Hi >> Mi;
		Hi = Hi * 60 + Mi;
		v.push_back(Hi);
	}
	int x;
	cin >> x;
	int A, B;
	cin >> A >> B;
	int sum = A * 60 + B;
	int min = 0;
	for (int i = 0; i < N; ++i)
	{
		if (v[i] + x <= sum && min < v[i])
		{
			min = v[i];
		}
	}
	Hi = min / 60;
	Mi = min - Hi * 60;
	cout << Hi << " " << Mi << endl;
	system("pause");
	return 0;
}