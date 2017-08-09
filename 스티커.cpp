#include<iostream>
#include<algorithm>

using namespace std;
int main()
{
	int test_case;
	cin >> test_case;
	while (test_case--)
	{
		int num;
		cin >> num;

		int **arr = new int*[2];
		int **dp = new int*[2];
		for (int i = 0; i < 2; i++)
		{
			arr[i] = new int[num];
			dp[i] = new int[num];
		}

		for (int i = 0; i < 2; i++)
			for (int j = 0; j < num; j++)
				cin >> arr[i][j];

		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		dp[0][1] = arr[1][0] + arr[0][1];
		dp[1][1] = arr[0][0] + arr[1][1];

		for (int i = 2; i < num; i++)
		{
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2])+arr[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2])+arr[1][i];
		}

		cout << max(dp[0][num - 1], dp[1][num - 1]) << endl;

		for (int i = 0; i < 2; i++)
		{
			delete[] arr[i];
			delete[] dp[i];
		}

		delete[] arr;
		delete[] dp;
	}
	return 0;
}
