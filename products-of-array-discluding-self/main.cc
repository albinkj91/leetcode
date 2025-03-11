#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

vector<int> productExceptSelf(vector<int> & nums)
{
	int product{1};
	for(unsigned i{}; i < nums.size(); ++i)
	{
		if(nums.at(i) != 0)
			product *= nums.at(i);
	}

	for(unsigned i{}; i < nums.size(); ++i)
	{
		if(nums.at(i) != 0)
			nums.at(i) = product / nums.at(i);
		else
			nums.at(i) = 0;
	}
	return nums;
}

int main()
{
	vector<int> nums{-1,0,1,2,3};
	productExceptSelf(nums);

	copy(nums.begin(), nums.end(),
			ostream_iterator<int>{cout, "\n"});
	cout << endl;
}
