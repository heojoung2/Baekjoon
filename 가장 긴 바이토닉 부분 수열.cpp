#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int num;
	cin >> num;

	int arr[1000] = { 0, };
	int left_num = 1;
	int right_num = 1;
	int left_arr[1000] = { 0, };
	int right_arr[1000] = { 0, };
	int left_result_arr[1000] = { 0, };
	int right_result_arr[1000] = { 0, };

	for (int i = 0; i < num; i++)
		cin >> arr[i];

	left_arr[0] = arr[0];
	right_arr[0] = arr[num-1];
	left_result_arr[0] = 1;
	right_result_arr[num-1] = 1;

	for (int first_i = 1; first_i < num; first_i++)
	{
		for (int second_i = 0; second_i < left_num; second_i++)
		{
			if (arr[first_i] <= left_arr[second_i])
			{
				left_arr[second_i] = arr[first_i];
				break;
			}
			else if (second_i == left_num - 1)
			{
				left_arr[second_i + 1] = arr[first_i];
				left_num++;
				break;
			}
		}

		for (int second_i = 0; second_i < right_num; second_i++)
		{
			if (arr[num-first_i-1] <= right_arr[second_i])
			{
				right_arr[second_i] = arr[num-first_i-1];
				break;
			}
			else if (second_i == right_num - 1)
			{
				right_arr[second_i + 1] = arr[num - first_i-1];
				right_num++;
				break;
			}
		}

		left_result_arr[first_i] = left_num;
		right_result_arr[num-first_i - 1] = right_num;
	}

	int result = 0;
	for (int i = 0; i < num; i++)
		result = max(result,left_result_arr[i]+right_result_arr[i]-1);
	cout << result << endl;

	return 0;
}

