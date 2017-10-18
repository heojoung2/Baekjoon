#include<iostream>
#include<queue>

using namespace std;
int main()
{
	int row, col;
	cin >> col >> row;

	int **table = new int*[row];
	for (int i = 0; i < row; i++)
		table[i] = new int[col];

	queue< pair < int, int > > queue;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> table[i][j];
			if (table[i][j] == 1)
			{
				queue.push(make_pair(i, j));
			}
		}
	}

	if (queue.size() == row*col)
	{
		cout << 0 << endl;
		return 0;
	}

	int result = 0;
	int direction_x[4] = {0,0,-1,1};
	int direction_y[4] = {-1,1,0,0};
	while(!queue.empty())
	{
		int size = queue.size();
		for (int i = 0; i < size; i++)
		{
			int x = queue.front().first;
			int y = queue.front().second;
			queue.pop();

			for (int j = 0; j < 4; j++)
			{
				int x2 = x + direction_x[j];
				int y2 = y + direction_y[j];

				if (x2<0 || y2<0 || x2>row - 1 || y2>col - 1)
					continue;
				else if (table[x2][y2] == 0)
				{
					queue.push(make_pair(x2,y2));
					table[x2][y2]=1;
				}
			}
		}
		result++;
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (table[i][j] == 0)
			{
				cout << -1 << endl;
				return 0;
			}
		}
	}

	cout << result-1 << endl;

	for (int i = 0; i < row; i++)
		delete[] table[i];
	delete[] table;
	return 0;
}