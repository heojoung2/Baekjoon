/* 
KMP알고리즘 ( 문자열검색 O(N+M) )
공백을 포함한 문자입력
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int cnt = 0;
vector<int> result;
int pi[1000000] = { 0 ,};

void Pi_function(string string)
{
	int j = 0;
	for (int i = 1; i < string.length(); i++) {
		while (j > 0 && string[i] != string[j])
			j = pi[j - 1];
		if (string[i] == string[j])
			pi[i] = ++j;
	}
}

void kmp(string string1, string string2)
{
	int j = 0;
	for (int i = 0; i <string1.length(); i++)
	{
		while (j > 0 && string1[i] != string2[j])
		{
			j = pi[j - 1];
		}
		if (string1[i] == string2[j])
		{
			if (j == string2.length() - 1)
			{
				cnt++;
				result.push_back(i - string2.length()+1);
				j = pi[j];
			}
			else
				j++;
		}
	}
}

int main()
{
	string string1, string2;
	getline(cin, string1);
	getline(cin, string2);

	Pi_function(string2);
	kmp(string1, string2);

	cout << cnt << endl;
	for (int i = 0; i < result.size(); i++)
		cout << result[i]+1 <<" ";
	cout << endl;

	return 0;
}
