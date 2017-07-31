#include<iostream>

using namespace std;
int main()
{
	int N, K, B;
	int arr[100001] = { 0, };

	cin >> N >> K >> B;
	for (int i = 0; i < B; i++)
	{
		int val;
		cin >> val;
		arr[val] = 1;
	}

	int cnt = 0;
	for (int i = 1; i <= K; i++)
		cnt += arr[i];
	int min = cnt;

	for (int i = 2; i <= N - K + 1; i++)
	{
		cnt -= arr[i-1];
		cnt += arr[i+K-1];
		if (min > cnt)
			min = cnt;
	}
	cout << min << endl;
	return 0;
}