#include<iostream>
#include<stack>
#include<cstring>
#include<cstdio>

using namespace std;
int main()
{
	int test_case;
	cin >> test_case;
	getchar();
	int num = 1;

	while (test_case--)
	{
		stack<char*> stack;
		
		char str[25];
		cin.getline(str,25);

		char *token = strtok(str, " ");
		while (token != NULL)
		{
			stack.push(token);
			token = strtok(NULL," ");
		}
		

		cout << "Case # " << num++ << ": ";
		while (!stack.empty())
		{
			cout<<stack.top()<<" ";
			stack.pop();
		}
		cout<<endl;
		
	}
	return 0;
}