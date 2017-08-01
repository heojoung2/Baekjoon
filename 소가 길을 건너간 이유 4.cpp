#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b)
{
	if (a.second < b.second)
		return 1;
	else
		return 0;
}

int main()
{
	int chicken_num, cow_num;
	cin >> chicken_num >> cow_num;

	vector<int> chicken;
	for (int i = 0; i < chicken_num; i++)
	{
		int val;
		cin >> val;
		chicken.push_back(val);
	}

	vector< pair<int, int> > cow;
	for (int i = 0; i < cow_num; i++)
	{
		int val1, val2;
		cin >> val1 >> val2;
		cow.push_back(pair<int,int>(val1, val2));
	}

	sort(chicken.begin(), chicken.end());
	sort(cow.begin(), cow.end(),compare);

	int cnt = 0;
	for (int i = 0; i < chicken_num; i++)
	{
		for (int j = 0; j < cow.size(); j++)
		{
			if (cow[j].first <= chicken[i] && chicken[i] <= cow[j].second)
			{
				cow.erase(cow.begin() + j);
				cnt++;
				break;
			}
		}
	}
	cout << cnt << endl;

	return 0;
}