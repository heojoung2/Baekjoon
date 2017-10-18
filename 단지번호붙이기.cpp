#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int direction_x[4] = {0,0,1,-1};
int direction_y[4] = {-1,1,0,0};

int DFS(int table[25][25], int x, int y, int size)
{
	int cnt = 0;
	table[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int x2 = x + direction_x[i];
		int y2 = y + direction_y[i];

		if (x2<0 || y2<0 || x2>size-1 || y2>size - 1)
			continue;
		else if (table[x2][y2] == 1)
		{
			cnt += (DFS(table, x2, y2, size)+1);
		}
	}
	return cnt;

}

int main()
{
	int size;
	cin >> size;
	
	char num;
	int table[25][25];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin >> num;
			table[i][j] = num - '0';
		}
	}

	int result = 0;
	vector<int> vector;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (table[i][j] == 1)
			{
				vector.push_back(DFS(table, i, j, size));
				result++;
			}
		}
	}
	cout << result << endl;

	sort(vector.begin(),vector.end());
	for (int i = 0; i < vector.size(); i++)
		cout << vector[i]+1 << endl;

	return 0;
}