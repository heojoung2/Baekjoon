#include<iostream>

using namespace std;

int main()
{
	int num;
	cin >> num;

	int result_num = 1;
	int *arr = new int[1000000];
	int *result_arr = new int[1000000];
	for (int i = 0; i < num; i++)
		cin >> arr[i];

	result_arr[0] = arr[0];
	for (int first_i = 1; first_i < num; first_i++)
	{
		for (int second_i = 0; second_i < result_num; second_i++)
		{
			if (arr[first_i] <= result_arr[second_i])
			{
				result_arr[second_i] = arr[first_i];
				break;
			}
			else if (second_i == result_num - 1)
			{
				result_arr[second_i+1] = arr[first_i];
				result_num++;
				break;
			}
		}		
	}
	cout << result_num << endl;

	delete[] arr;
	delete[] result_arr;

	return 0;
}

