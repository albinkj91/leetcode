#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target)
{
	if(nums.at(0) == target)
		return 0;
	int left{0};
	int right{static_cast<int>(nums.size()) - 1};
	int mid{right / 2};
	while(left != right)
	{
		if(nums.at(mid) < target)
			left = mid + 1;
		else if(nums.at(mid) > target)
			right = mid - 1;

		mid = (right+left) / 2;
		if(nums.at(mid) == target)
			return mid;
	}
	return -1;
}

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		cerr << "Invalid arguments" << endl;
		return -1;
	}

	vector<int> nums{2, 5};
	int target{stoi(argv[1])};
	int index{search(nums, target)};
	cout << index << endl;
}
