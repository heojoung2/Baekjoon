#include<iostream>
#include<queue>

using namespace std;

int direction_x[4] = {0,0,1,-1};
int direction_y[4] = {-1,1,0,0};

void DFS(int table[50][50], int x, int y, int row, int col)
{
	table[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int x2 = x + direction_x[i];
		int y2 = y + direction_y[i];

		if (x2<0 || y2<0 || x2>row - 1 || y2>col - 1)
			continue;
		else if(table[x2][y2] == 1)
			DFS(table,x2, y2, row, col);
	}

}

int main()
{
	int test_case;
	cin >> test_case;
	while (test_case--)
	{
		int table[50][50] = { 0, };

		int row, col, num;
		cin >> row >> col >> num;

		while (num--)
		{
			int x, y;
			cin >> x >> y;
			table[x][y] = 1;
		}

		int result = 0;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (table[i][j] == 1)
				{
					DFS(table,i, j, row, col);
					result++;
				}
			}
		}
		cout << result << endl;
	}
	return 0;
}