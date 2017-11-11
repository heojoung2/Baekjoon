#include<iostream>

using namespace std;
int main()
{
	int table[101][101] = { 0, };
	int size,num;
	cin >> size>>num;

	int first, second;
	while(num--)
	{
		cin >> first >> second;
		table[first][second] = 1;
	}

	for (int k = 1; k <= size; k++)
	{
		for (int i = 1; i <= size; i++)
		{
			for (int j = 1; j <= size; j++)
			{
				if (table[i][k] == 1 && table[k][j] == 1)
					table[i][j] = 1;
			}
		}
	}

	for (int i = 1; i <= size; i++)
	{
		int count = 0;
		for (int j = 1; j <= size; j++)
		{
			if (table[i][j] == 0 && table[j][i] == 0)
				count++;
		}
		cout << count-1 << endl;
	}
	
	return 0;
}