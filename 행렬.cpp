#include<iostream>
#include<string>

using namespace std;
int main()
{
	int row, col;
	int arr[50][50] = { 0, };
	int change_arr[50][50] = { 0, };
	string str;
	cin >> row >> col;

	for (int i = 0; i < row; i++)
	{
		cin >> str;
		for (int j = 0; j < col; j++)
			arr[i][j] = str[j] - '0';
	}

	for (int i = 0; i < row; i++)
	{
		cin >> str;
		for (int j = 0; j < col; j++)
			change_arr[i][j] = str[j] - '0';
	}

	int cnt = 0;

	for (int i = 0; i < row - 2; i++)
	{
		for (int j = 0; j < col - 2; j++)
		{
			if (arr[i][j] != change_arr[i][j])
			{
				cnt++;
				for (int change_i = i; change_i < i + 3; change_i++)
				{
					for (int change_j = j; change_j < j + 3; change_j++)
					{
						if (arr[change_i][change_j] == 1)
							arr[change_i][change_j] = 0;
						else
							arr[change_i][change_j] = 1;
					}
				}
			}
		}
	}

	bool flag = false;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j]!=change_arr[i][j])
			{
				cnt = -1;
				flag = true;
				break;
			}
		}
		if (flag == true)
			break;
	}
	cout << cnt << endl;

	return 0;
}

