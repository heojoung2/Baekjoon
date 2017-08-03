#include<iostream>
#include<string>

using namespace std;

bool Check(string str, int *arr)
{
	int size = str.length();
	int before_index = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[str[i] - 'a'] == 0)
			arr[str[i]-'a']++;
		else
		{
			if (str[i] - 'a' != before_index)
				return false;
		}
		before_index = str[i]-'a';
	}
	return true;
}

int main()
{
	int cnt = 0;
	
	int num;
	cin >> num;
	for (int i = 0;i < num; i++)
	{
		int arr[26] = { 0, };
		string str;
		cin >> str;

		if (Check(str,arr))
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}