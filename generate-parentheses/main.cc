#include <iostream>
#include <vector>
using namespace std;

vector<string> results{};

void gen(string & s, int left, int right)
{
	if(left == 0 && right == 0)
	{
		results.push_back(s);
	}
	else if(left == right)
	{
		--left;
		s.push_back('(');
		gen(s, left, right);
	}
	else if(left == 0)
	{
		--right;
		s.push_back(')');
		gen(s, left, right);
	}
	else
	{
		string cpy{s};
		s.push_back('(');
		--left;
		gen(s, left, right);
		cpy.push_back(')');
		--right;
		gen(cpy, left+1, right);
	}
}

vector<string> generateParentheses(int n)
{
	string s{""};
	gen(s, n, n);
	return results;
}

int main()
{
	int n{3};
	generateParentheses(n);

	for(auto& s :  results)
		cout << s << '\n';
	cout << endl;
}
