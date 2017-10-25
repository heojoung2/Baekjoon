#include<iostream>
#include<string>
#include<cmath>

using namespace std;
int main()
{
	int N;
	cin >> N;

	int cnt = 0;
	int i = 1;
	for (i;; i++)
	{
		N -= (9 * pow(10, i - 1));
		if (N> 0)
			cnt += (9 * pow(10, i - 1)*i);
		else
		{
			N += (9 * pow(10, i - 1));
			cnt += N*i;
			break;
		}
	}
	cout << cnt<<endl;
	return 0;
}