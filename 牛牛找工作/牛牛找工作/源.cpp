#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int>Di, Pi;
	int d, p;
	for (int i = 0; i < N; ++i)
	{
		cin >> d;
		cin >> p;
		Di.push_back(d);
		Pi.push_back(p);
	}
	vector<int>Ai;
	int A;
	for (int i = 0; i < M; ++i)
	{
		cin >> A;
		Ai.push_back(A);
	}
	vector<int>res;
	int Max_P = 0; //用来存放最大报酬
	for (int j = 0; j < M; ++j)  //循环人数
	{
		int Max_P = 0;
		for (int i = 0; i < N; ++i) //循环难度
		{
			if (Ai[j] >= Di[i] && Max_P <= Pi[i])
			{
				Max_P = Pi[i];
			}
		}
		res.push_back(Max_P);
	}
	
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << " ";
	}
	system("pause");
	return 0;
}