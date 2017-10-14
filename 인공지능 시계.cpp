#include<iostream>

using namespace std;
int main()
{
	int hour, minute, second, cooking_time;
	cin >> hour >> minute >> second >>cooking_time;

	int time = second + minute * 60 + hour * 60 * 60 + cooking_time;

	hour = (time / 3600)%24;
	minute = (time % 3600) / 60;
	second = (time % 3600) % 60;

	cout << hour << " " << minute << " " << second << " " << endl;
	return 0;
}