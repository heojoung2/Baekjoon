#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

bool compare(string a, string b)
{
	if (a.length() < b.length())
		return true;
	else if(a.length() > b.length())
		return false;
	else
	{
		if (a < b)
			return true;
		else
			return false;
	}
}

int main()
{
	int num;
	cin >> num;
	string arr[20000];
	for (int i = 0; i < num; i++)
		cin >> arr[i];
	sort(arr, arr + num, compare);
	
	string before = arr[0];
	cout << arr[0] <<endl;
	for (int i = 1; i < num; i++)
	{
		if (before == arr[i])
			continue;
		before = arr[i];
		cout << arr[i] << endl;
	}

	return 0;
}
