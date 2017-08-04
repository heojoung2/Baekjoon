#include<iostream>
#include<string>

using namespace std;
int main()
{
	int check[26][26] = { 0, };
	bool back[26] = { 0, };

	string str;
	cin >> str;
	
	for (int i = 0; i < 51; i++)
	{
		if (back[str[i]-'A']==true)
			continue;
		for (int j = i+1; j < 52; j++)
		{
			if (str[i] == str[j])
			{
				back[str[i] - 'A'] = true;
				break;
			}
			else
				check[str[i] - 'A'][str[j] - 'A']++;
		}
	}

	int cnt = 0;
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (check[i][j] == 1)
				cnt++;
		}
	}
	cout << cnt/2 << endl;
	return 0;
}
