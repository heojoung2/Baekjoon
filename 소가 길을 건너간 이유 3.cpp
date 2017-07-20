#include <iostream>
#include <algorithm>

using namespace std;

class Cow
{
private:
	int val1, val2;
public:
	Cow() {};
	void Set_val1(int val);
	void Set_val2(int val);
	int Get_val1();
	int Get_val2();
};

void Cow::Set_val1(int val)
{
	val1 = val;
}

void Cow::Set_val2(int val)
{
	val2 = val;
}

int Cow::Get_val1()
{
	return val1;
}

int Cow::Get_val2()
{
	return val2;
}

bool compare(Cow a, Cow b)
{
	if (a.Get_val1() < b.Get_val1())
		return true;
	else
		return false;
}

int main()
{
	int num,val1,val2;
	cin >> num;
	
	Cow cow[100];

	for (int i = 0; i < num; i++)
	{
		cin >> val1>>val2;
		cow[i].Set_val1(val1);
		cow[i].Set_val2(val2);
	}

	sort(cow, cow + num, compare);

	int time = 0;
	for (int i = 0;; i++)
	{
		if (cow[i].Get_val1()>=time)
			time = cow[i].Get_val1() + cow[i].Get_val2();
		else
			time += cow[i].Get_val2();
		if (i==num-1)
			break;
	}

	cout << time << endl;

	return 0;
}