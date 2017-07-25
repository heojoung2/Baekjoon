/*Counting sorting(계수정렬)
O(n)
숫자가 띄엄띄엄있으면 메모리낭비
숫자가 몰려있을 때 사용하면 효율적
*/

#include <stdio.h>
#define max_size 10001

int max(int val1, int val2)
{
	if (val1 > val2)
		return val1;
	return val2;
}

int main()
{
	int sum[max_size] = { 0, };

	int N;
	scanf("%d", &N);

	int val,i,j;
	int max_val = 0;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &val);
		sum[val]++;
		max_val = max(max_val, val);
	}

	for (i = 1; i < max_val + 1; i++)
	{
		sum[i] += sum[i - 1];
		int loop = sum[i] - sum[i - 1];
		for (j = 0; j < loop; j++)
			printf("%d\n", i);
	}
	return 0;
}