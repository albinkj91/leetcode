#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int evalRPN(vector<string>& tokens)
{
	stack<int> s{};
	for(auto& token : tokens)
	{
		if(token == "+")
		{
			int num1{s.top()};
			s.pop();
			int num2{s.top()};
			s.pop();
			s.push(num1 + num2);
		}
		else if(token == "-")
		{
			int num1{s.top()};
			s.pop();
			int num2{s.top()};
			s.pop();
			s.push(num2 - num1);
		}
		else if(token == "*")
		{
			int num1{s.top()};
			s.pop();
			int num2{s.top()};
			s.pop();
			s.push(num1 * num2);
		}
		else if(token == "/")
		{
			int num1{s.top()};
			s.pop();
			int num2{s.top()};
			s.pop();
			s.push(num2 / num1);
		}
		else
		{
			s.push(stoi(token));
		}
	}
	return s.top();
}

int main()
{
	vector<string> tokens{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
	int result{evalRPN(tokens)};
	cout << "Result: " << result << endl;
}
