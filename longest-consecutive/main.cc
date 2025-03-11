#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestConsecutive(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int max_count{};
	int count{};
	int last_num{nums.at(0)};

	for(size_t i{1}; i < nums.size(); ++i)
	{
		cout << "last: " << last_num << endl;
		cout << "curr: " << nums.at(i) << endl;
		if((last_num + 1) == (nums.at(i)))
		{
			++count;
			cout << "count: " << count << endl;
		}
		else if(last_num == nums.at(i))
		{
			last_num = nums.at(i);
			continue;
		}
		else
		{
			count = 0;
		}
		if(count > max_count)
		{
			max_count = count;
			cout << "max: " << max_count << endl;
		}
		last_num = nums.at(i);
	}
	return max_count + 1;
}

int main()
{
	//vector<int> nums{1,0,1,2};
	//				 0,1,1,2

	vector<int> nums{0,3,7,2,5,8,4,6,0,1};
	//				 0,0,1,2,3,4,5,6,7,8};
	cout << longestConsecutive(nums) << endl;
}
