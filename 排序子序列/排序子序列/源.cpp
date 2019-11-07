#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int num = 0;
	vector<int> arr;
	int ret = 1;

	cin >> num;
	arr.resize(num);
	for (int i = 0; i < num; i++)
		cin >> arr[i];

	for (int i = 1; i < num - 1; ++i)
	{
		if ((arr[i - 1] > arr[i] && arr[i] < arr[i + 1])
			|| (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]))
		{
			ret++;
			if (i != num - 3)
				i++;
		}
	}

	cout << ret << endl;
	system("pause");
	return 0;
}

