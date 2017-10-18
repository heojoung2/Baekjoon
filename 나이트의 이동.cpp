#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int main()
{
	int direction_x[8] = {-2,-1,1,2,2,1,-1,-2};
	int direction_y[8] = {1,2,2,1,-1,-2,-2,-1};

	int test_case;
	cin >> test_case;
	while (test_case--)
	{
		queue< pair < int, int> > queue;
		int table[300][300] = { 0, };
		int table_size;
		cin >> table_size;

		int start_x, start_y, end_x,end_y;
		cin >> start_x >> start_y >>end_x>>end_y;
		queue.push(make_pair(start_x, start_y));
		table[start_x][start_y] = 1;

		int result = 1;
		bool end_flag = false;

		while (!queue.empty())
		{
			int size = queue.size();;
			for(int i=0;i<size;i++)
			{
				int x = queue.front().first;
				int y = queue.front().second;
				queue.pop();
				
				for (int j = 0; j < 8; j++)
				{
					int x2 = x + direction_x[j];
					int y2 = y + direction_y[j];

					if (x2<0 || y2<0 || x2>table_size - 1 || y2>table_size - 1)
						continue;
					else if (x2==end_x && y2==end_y)
					{
						end_flag = true;
						break;
					}
					else if (table[x2][y2] == 0)
					{
						table[x2][y2] = 1;
						queue.push(make_pair(x2, y2));
					}
				}
				if (end_flag == true)
					break;
			}
			if (end_flag == true)
				break;
			result++;
		}
		if (start_x == end_x && start_y == end_y)
			cout << 0 << endl;
		else
			cout << result << endl;
	}
}
