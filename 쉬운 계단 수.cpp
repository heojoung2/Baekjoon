#include<iostream>

using namespace std;
int main()
{
	int num;
	cin >> num;

	long long table[100][10] = {0 , };
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i == 0 )
				table[i][j] = 1;
			else if (1 <= j&& j <= 8)
				table[i][j] = table[i - 1][j - 1] + table[i - 1][j + 1];
			else if (j == 0)
				table[i][j] = table[i - 1][j + 1];
			else if(j==9)
				table[i][j] = table[i - 1][j - 1];
			table[i][j] %= 1000000000;
		}
	}

	long long sum = 0;
	for (int i = 1; i < 10; i++)
		sum+=table[num - 1][i];
	cout << sum%1000000000 << endl;

	return 0;
}
