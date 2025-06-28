#include <iostream>
#include <stack>
using namespace std;

#define EMPTY 0
#define NOT_EMPTY 1

bool isValid(string const& s)
{
	bool state{EMPTY};
	cout << "State: " << state << endl;;
	stack<char> pile{};
	for(size_t i{}; i < s.size(); ++i)
	{
		if(state == EMPTY)
		{
			if(s.at(i) == '(' || s.at(i) == '[' || s.at(i) == '{')
			{
				pile.push(s.at(i));
				state = NOT_EMPTY;
				cout << "State: " << state << endl;;
			}
			else
			{
				return false;
			}
		}
		else
		{
			if(s.at(i) == '(' || s.at(i) == '[' || s.at(i) == '{')
			{
				pile.push(s.at(i));
			}
			else if(pile.top()+1 == s.at(i) || pile.top()+2 == s.at(i))
			{
				pile.pop();
				if(pile.empty())
					state = EMPTY;
				cout << "State: " << state << endl;;
			}
			else
				return false;
		}
	}
	if(pile.empty())
		return false;
	return true;
}

int main()
{
	string s{"(])"};
	bool result{isValid(s)};
	cout << result << endl;
}
