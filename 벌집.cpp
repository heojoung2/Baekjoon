#include<iostream>

using namespace std;
int main()
{
	int number;
	cin >> number;
	
	int sum = 1;
	int i;
	for(i=1;;i++)
	{
		if (sum >= number)
			break;
		sum += 6 * i;
	}

	cout << i << endl;
	return 0;
}