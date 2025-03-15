#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures)
{
	stack<int> s{};
	vector<int> days{};
	int count{0};
	for(size_t i{0}; i < temperatures.size(); ++i)
	{
		cout << "temp: " << temperatures.at(i) << ", ";
		while(!s.empty() && (temperatures.at(s.top()) < temperatures.at(i)))
		{
			cout << "count: " << count << ", ";
			days.at(s.top()) = i - s.top();
			s.pop();
		}
		cout << endl;
		s.push(i);
		days.push_back(0);
		++count;
	}
	return days;
}

int main()
{
	//Should print [1,1,4,2,1,1,0,0]
	vector<int> temperatures{73, 74, 75, 71, 69, 72, 76, 73};
	vector<int> result{dailyTemperatures(temperatures)};
	copy(result.begin(), result.end(),
			ostream_iterator<int>(cout, " "));
}
