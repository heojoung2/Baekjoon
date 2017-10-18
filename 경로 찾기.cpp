#include<iostream>
#include<queue>

using namespace std;
int main()
{
	int size;
	cin >> size;

	int table[100][100];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			cin >> table[i][j];

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++)
			{
				if (table[j][i] == 1 && table[i][k] == 1)
					table[j][k] = 1;
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << table[i][j] << " ";
		cout << endl;
	}
	return 0;
}