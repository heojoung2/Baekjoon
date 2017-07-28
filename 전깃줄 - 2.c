#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int val1, val2;
}Wire;



int compare(const void *a, const void * b) {

	Wire *v1 = (Wire *)a;
	Wire *v2 = (Wire*)b;

	if (v1->val1 > v2->val1)
		return 1;
	else
		return -1;
}

int main()
{
	int num, val1, val2;
	scanf("%d", &num);

	Wire *wire = (Wire*)malloc(sizeof(Wire)*num);

	int i;
	for (i = 0; i < num; i++)
	{
		scanf("%d %d", &val1, &val2);
		wire[i].val1 = val1;
		wire[i].val2 = val2;
	}

	qsort(wire,num,sizeof(Wire),compare);

	int lis_num = 1;
	int first_i, second_i;
	Wire *lis_arr = (Wire*)malloc(sizeof(Wire)*num);
	int result[100000] = { 0, };

	lis_arr[0] = wire[0];
	result[0] = 0;
	for (first_i = 1; first_i < num; first_i++)
	{
		for (second_i = 0; second_i < lis_num; second_i++)
		{
			if (wire[first_i].val2 <= lis_arr[second_i].val2)
			{
				lis_arr[second_i] = wire[first_i];
				result[first_i] = second_i;
				break;
			}
			else if (second_i == lis_num - 1)
			{
				lis_arr[second_i + 1] = wire[first_i];
				lis_num++;
				result[first_i] = second_i + 1;
				break;
			}
		}
	}

	printf("%d\n", num - lis_num);

	int answer[100000] = { 0, };
	int answer_size = 0;
	for (i = num - 1; i >= 0; i--)
	{
		if (result[i] == (lis_num - 1))
			lis_num--;
		else
			answer[answer_size++] = wire[i].val1;

		if (lis_num < 0)
			break;
	}

	for (i = answer_size - 1; i >= 0; i--)
		printf("%d\n", answer[i]);

	free(wire);
	free(lis_arr);

	return 0;
}