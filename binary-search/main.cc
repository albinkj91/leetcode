#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target)
{
	int current{static_cast<int>(nums.size()) / 2};
	int step{current / 2};
	while(nums.at(current) != target)
	{
		cout << "current: " << current << endl;
		cout << "step: " << step << endl;
		if(step == 0)
		{
			return -1;
		}
		else if(nums.at(current) < target)
		{
			current += step;
		}
		else if(nums.at(current) > target)
		{
			current -= step;
		}
		step /= 2;
	}
	return current;
}

int main()
{
	vector<int> nums{-1, 0, 3, 5, 9, 12};
	int target{-1};
	int index{search(nums, target)};
	cout << index << endl;
}
