#include<iostream>

using namespace std;

int main()
{
	int length;
	cin >> length;
	int stick[7] = { 64,32,16,8,4,2,1 };
	int cnt = 0;

	for (int i = 0; i < 7; i++)
	{
		if (length >= stick[i])
		{
			length -= stick[i];
			cnt++;
		}
		if (length == 0)
			break;
	}

	cout << cnt << endl;

	return 0;
}
