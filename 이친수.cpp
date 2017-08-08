#include<iostream>
#include<algorithm>

using namespace std;
int main()
{
	int number;
	cin >> number;
	long long dp[90][2] = { 0, };

	dp[0][0] = 0;
	dp[0][1] = 1;
	for (int i = 1; i < number; i++)
	{
		dp[i][0] = dp[i - 1][1]+dp[i-1][0];
		dp[i][1] = dp[i - 1][0];
	}
	cout << dp[number-1][0]+dp[number - 1][1] << endl;
	return 0;
}
