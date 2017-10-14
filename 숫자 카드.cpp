#include<iostream>
#include<algorithm>
#include<map>
#include<cstdio>

using namespace std;
int main()
{
	int card1_num, card2_num;
	map<int, int> map;

	scanf("%d", &card1_num);
	int *card1 = new int[card1_num];
	for (int i = 0; i < card1_num; i++)
	{
		scanf("%d", &card1[i]);
		map.insert(pair<int, int>(card1[i], 1));
	}

	int num;
	scanf("%d", &card2_num);
	for (int i = 0; i < card2_num; i++)
	{
		scanf("%d",&num);
		try {
			printf("%d ", map[num]);
		}
		catch (exception e)
		{
			printf("0 ");
		}
	}

	delete[] card1;
	return 0;
}