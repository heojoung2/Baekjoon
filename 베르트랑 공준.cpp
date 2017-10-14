#include<iostream>
#include<cstring>

using namespace std;

int Range(int number,int *arr)
{
	int cnt = 0;
	for (int i = number+1; i <= 2 * number; i++)
	{
		if (arr[i] != 0)
			cnt++;
	}
	return cnt;
}

int main()
{
	const int size = 246914;
	int arr[size];
	for (int i = 0; i < size; i++)
		arr[i] = 1;


	for (int i = 2; i < size; i++)
	{
		if (arr[i] != 0)
		{
			for (int j = 2 * i; j < size; j += i)
				arr[j] = 0;
		}
	}

	for (int i = 0;; i++)
	{
		int number;
		cin >> number;
		if (number == 0)
			break;
		cout<<Range(number,arr)<<endl;
	}
	return 0;
}
