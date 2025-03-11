#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target)
{
	int length{static_cast<int>(numbers.size()-1)};
	int i1{};
	int i2{length};

	while(true)
	{
		int sum{numbers.at(i1)+numbers.at(i2)};
		if(sum < target)
			++i1;
		else if(sum > target)
			--i2;
		else
			return vector<int>{i1+1, i2+1};
	}
	return vector<int>{};
}

int main()
{
	vector<int> numbers{0, 0, 0, 0, 0, 0, 2, 3, 9, 9, 9, 9, 9, 9};
	int target{5};
	vector<int> result{twoSum(numbers, target)};
	copy(result.begin(), result.end(),
			ostream_iterator<int>{cout, " "});
	cout << endl;
}
