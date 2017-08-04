#include<iostream>

using namespace std;

int program_size[100] = { 0, };
int program[100][1000] = { 0, };
int pi[1000][1000] = { 0 , };

void Pi_function(int min_index, int start_index, int size)
{
	int j = start_index;
	for (int i = start_index + 1; i < start_index + size; i++)
	{
		while (j > start_index && program[min_index][i] != program[min_index][j])
			j = pi[start_index][j - 1];
		if (program[min_index][i] == program[min_index][j])
			pi[start_index][i] = ++j;
	}
}

bool Kmp(int start_index, int program_number, int virus_size, int min_index)
{
	int j = start_index;
	for (int i = 0; i < program_size[program_number]; i++)
	{
		while (j > start_index && program[program_number][i] != program[min_index][j])
			j = pi[start_index][j - 1];
		if (program[program_number][i] == program[min_index][j])
		{
			if (j == start_index + virus_size - 1)
				return true;
			else
				j++;
		}
	}

	j = start_index;
	for (int i = program_size[program_number] - 1; i >= 0; i--)
	{
		while (j > start_index && program[program_number][i] != program[min_index][j])
			j = pi[start_index][j - 1];
		if (program[program_number][i] == program[min_index][j])
		{
			if (j == start_index + virus_size - 1)
				return true;
			else
				j++;
		}
	}

	return false;
}

int main()
{
	int program_num, virus_size;
	cin >> program_num >> virus_size;

	int min = 1000;
	int min_index;
	for (int i = 0; i < program_num; i++)
	{
		cin >> program_size[i];
		for (int j = 0; j < program_size[i]; j++)
			cin >> program[i][j];
		if (program_size[i] < min)
		{
			min = program_size[i];
			min_index = i;
		}
	}

	for (int i = 0; i < program_size[min_index] - virus_size + 1; i++)
		Pi_function(min_index, i, virus_size);

	bool flag = false;
	for (int i = 0; i < program_size[min_index] - virus_size + 1; i++)
	{
		int cnt = 0;
		for (int j = 0; j < program_num; j++)
		{
			if (j == min_index)
				continue;
			if (Kmp(i, j, virus_size, min_index) == true)
				cnt++;
		}
		if (cnt == program_num - 1)
		{
			flag = true;
			break;
		}
	}

	if (flag == true)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}