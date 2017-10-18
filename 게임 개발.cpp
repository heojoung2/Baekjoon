#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
	int building_num;
	cin >> building_num;

	vector< vector<int> > table;
	table.assign(building_num+1,vector<int>(building_num+1,0));
	int time[501] = { 0, };
	int result[501] = { 0, };
	
	int i, j;
	for (i = 0; i < table.size(); i++)
	{
		table[i][0] = i;
		table[0][i] = i;
		if (i == 0)
			continue;
		else
		{
			cin >> time[i];
			result[i] = time[i];

			int val;
			cin >> val;
			while (val != -1)
			{
				table[i][val] = 1;
				cin >> val;
			}
		}
	}

	for (i = 1; i < table.size(); i++)
	{
		int cnt = 0;
		for (j = 1; j < table[0].size(); j++)
		{
			if (table[i][j] == 0)
				cnt++;
		}

		if (cnt == building_num)
		{
			for (int k = 1; k < table.size(); k++)
			{
				if (table[k][table[i][0]] != 0)
				{
					result[table[k][0]] = max(result[table[k][0]], result[table[i][0]] + time[table[k][0]]);
					table[k][table[i][0]] = 0;
				}
			}
			table.erase(table.begin() + i);
			i = 0;
			j = 0;
		}
	}
	for (int i = 1; i <= building_num; i++)
		cout << result[i] << endl;
	return 0;
}
