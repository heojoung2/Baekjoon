#include<iostream>

using namespace std;

int main()
{
	int num;
	cin >> num;

	int lis_num = 1;
	int *arr = new int[num];
	int *lis_arr = new int[num];
	int *result = new int[num];
	int *answer = new int[num];

	for (int i = 0; i < num; i++)
		cin >> arr[i];

	lis_arr[0] = arr[0];
	result[0] = 0;
	for (int first_i = 1; first_i < num; first_i++)
	{
		for (int second_i = 0; second_i < lis_num; second_i++)
		{
			if (arr[first_i] <= lis_arr[second_i])
			{
				lis_arr[second_i] = arr[first_i];
				result[first_i] = second_i;
				break;
			}
			else if (second_i == lis_num - 1)
			{
				lis_arr[second_i + 1] = arr[first_i];
				lis_num++;
				result[first_i] = second_i+1;
				break;
			}
		}
	}
	cout << lis_num << endl;
	
	int answer_size = 0;
	for (int i = num - 1; i >= 0; i--)
	{
		if (result[i]==(lis_num-1))
		{
			answer[answer_size++] = arr[i];
			lis_num--;
		}
		if (lis_num < 0)
			break;
	}

	for (int i = answer_size - 1; i >= 0; i--)
		cout << answer[i] << " ";
	cout << endl;

	delete[] arr;
	delete[] lis_arr;
	delete[] result;
	delete[] answer;

	return 0;
}

