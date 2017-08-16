#include<stdio.h>
#include<stdlib.h>


int find(int val, int *find_arr)
{
	if (find_arr[val] == 0)
		return val;
	find_arr[val] = find(find_arr[val], find_arr);
	return find_arr[val];
}

void fun_union(int val1, int val2, int* find_arr)
{
	int result1 = find(val1, find_arr);
	int result2 = find(val2, find_arr);

	if (result1 == result2)
		return;
	else
		find_arr[result1] = result2;
}

int main()
{
	int node, num;
	scanf("%d %d", &node, &num);

	int *find_arr = (int *)malloc(sizeof(int)*(node+1));
	memset(find_arr,0,sizeof(int)*(node+1));

	while (num--)
	{
		int val, val1, val2;
		scanf("%d %d %d", &val, &val1, &val2);
		if (val == 0)
			fun_union(val1, val2, find_arr);
		else
		{
			if (find(val1, find_arr) == find(val2, find_arr))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}

	free(find_arr);
	return 0;
}