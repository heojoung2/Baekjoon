#include<iostream>
#include<algorithm>

using namespace std;
int main()
{
	int dp[10000] = { 0, };
	int wine[10000] = { 0, };
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> wine[i];
		if (i == 0)
			dp[0] = wine[0];
		else if (i == 1)
			dp[1] = wine[0] + wine[1];
		else if (i == 2)
			dp[2] = max(dp[1], dp[0] + wine[2]);
		else
		{
			int val1 = dp[i - 1];
			int val2 = dp[i - 2] + wine[i];
			int val3 = dp[i - 3] + wine[i - 1] + wine[i];
			dp[i] = max(val1, max(val2, val3));
		}
	}
	cout << dp[num - 1] << endl;
	return 0;
}

