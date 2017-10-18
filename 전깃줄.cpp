#include<iostream>
#include<algorithm>

using namespace std;

class Wire
{
private:
	int val1, val2;
public:
	Wire() {};
	void Set_val1(int val);
	void Set_val2(int val);
	int Get_val1();
	int Get_val2();
};

void Wire::Set_val1(int val)
{
	val1 = val;
}

void Wire::Set_val2(int val)
{
	val2 = val;
}

int Wire::Get_val1()
{
	return val1;
}

int Wire::Get_val2()
{
	return val2;
}

bool compare(Wire a, Wire b)
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

	Wire wire[100];
	for (int i = 0; i < num; i++)
	{
		cin >> val1 >> val2;
		wire[i].Set_val1(val1);
		wire[i].Set_val2(val2);
	}

	sort(wire, wire + num, compare);

	int result_num = 1; 
	int result_arr[100] = { 0, };

	result_arr[0] = wire[0].Get_val2();
	for (int first_i = 1; first_i < num; first_i++)
	{
		for (int second_i = 0; second_i < result_num; second_i++)
		{
			if (wire[first_i].Get_val2() <= result_arr[second_i])
			{
				result_arr[second_i] = wire[first_i].Get_val2();
				break;
			}
			else if (second_i == result_num - 1)
			{
				result_arr[second_i + 1] = wire[first_i].Get_val2();
				result_num++;
				break;
			}
		}
	}

	cout << num-result_num << endl;
	return 0;
}
