#include<iostream>
#include<cmath>

double Distance(int x1,int y1, int x2, int y2)
{
	return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

using namespace std;
int main()
{
	int num, result;
	cin >> num;
	
	while (num--)
	{
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		
		double distance = Distance(x1, y1, x2, y2);

		if (distance == 0 && abs(r1 - r2) == 0)
			result = -1;
		else if (distance == 0 && abs(r1 - r2) > 0)
			result = 0;
		else if (distance == r1 + r2 || distance == abs(r1 - r2))
			result = 1;
		else if (distance < r1+r2 && distance > abs(r1-r2))
			result = 2;
		else
			result = 0;
		
		cout << result << endl;
	}
	return 0;
}