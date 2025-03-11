#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures)
{
	stack<int> s{};
	vector<int> days{};
	s.push(temperatures.at(0));
	for(size_t i{1}; i < temperatures.size(); ++i)
	{
		int count{1};
		while(!s.empty() && (s.top() < temperatures.at(i)))
		{
			days.push_back(count++);
			s.pop();
		}
		s.push(temperatures.at(i));
	}
	return days;
}

int main()
{
	vector<int> temperatures{73, 74, 75, 71, 69, 72, 76, 73};
	vector<int> result{dailyTemperatures(temperatures)};
	copy(result.begin(), result.end(),
			ostream_iterator<int>(cout, "\n"));
}
