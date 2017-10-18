/*
À§»óÁ¤·Ä(topological sort)
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int main()
{
	queue<int> queue;
	int singer_num, pd_num;
	cin >> singer_num >> pd_num;

	vector<vector<int>> table;
	table.assign(singer_num+1,vector<int>(singer_num+1,0));

	while (pd_num--)
	{
		int val;
		cin >> val;
		int start = 0;
		int end = 0;
		while (val--)
		{
			cin >> end;
			table[end][start]=1;
			start = end;
		}
	}
	int i, j;
	for (i = 0; i < table.size(); i++)
	{
		table[i][0] = i;
		table[0][i] = i;
	}

	for (i = 1; i < table.size(); i++)
	{
		int cnt = 0;
		for (j = 1; j < table[0].size(); j++)
		{
			if (table[i][j]== 0)
				cnt++;
		}
		if (cnt == singer_num)
		{
			queue.push(table[i][0]);
			for (int k = 1; k < table.size();k++)
				table[k][table[i][0]]=0;
			table.erase(table.begin() + i);
			i = 0;
			j = 0;
		}
	}

	if (queue.size() == singer_num)
	{
		while (!queue.empty())
		{
			cout << queue.front() << endl;
			queue.pop();
		}
	}
	else
		cout << "0"<<endl;

	return 0;
}
