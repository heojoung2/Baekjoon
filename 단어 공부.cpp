#include<iostream>
#include<string>

using namespace std;
int main()
{
	string str;
	int arr[26] = { 0, };
	cin >> str;

	int size = str.length();
	for (int i = 0; i < size; i++)
	{
		if (str[i] <= 'Z')
			arr[str[i] - 'A']++;
		else
			arr[str[i] - 'a']++;
	}
	int max = 0;
	int max_index = 0;
	for (int i = 0; i < 26; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
			max_index = i;
		}
	}

	int cnt = 0;
	bool flag = true;
	for (int i = 0; i < 26; i++)
	{
		if (max == arr[i])
		{
			cnt++;
			if (cnt == 2)
			{
				flag = false;
				break;
			}
		}
	}

	if (flag == true)
	{
		if (max_index < 26)
			cout << char(max_index + 'A') << endl;
	}
	else
		cout << "?" << endl;


	return 0;
}