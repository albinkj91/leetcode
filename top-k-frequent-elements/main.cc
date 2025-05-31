#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <map>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k)
{
	unordered_map<int, int> count{};
	for(auto const n: nums)
		if(count.find(n) != count.end())
			++count.at(n);
		else
			count.emplace(n, 1);

	vector<vector<int>> freq(nums.size() + 1);
	for(auto const& it : count)
		freq.at(it.second).push_back(it.first);

	vector<int> result{};
	for(size_t i{freq.size()-1}; i > 0; --i)
		for(auto const& it : freq.at(i))
		{
			result.push_back(it);
			if(static_cast<int>(result.size()) == k)
				return result;
		}
	return result;
}

void print(vector<int> & v)
{
	copy(v.begin(), v.end(),
			ostream_iterator<int>{cout, ","});
	cout << endl;
}

int main()
{
	vector<int> nums1{7,7};
	vector<int> nums2{1,2};
	vector<int> nums3{1,2,2,3,3,3};
	vector<int> nums4{5,2,6,8,2,45,78,34,23,2,46,67,68,4,3,4,6,8,9,7,8,87,79,6,34,3,5};
	auto result1{topKFrequent(nums1, 1)};
	auto result2{topKFrequent(nums2, 2)};
	auto result3{topKFrequent(nums3, 2)};
	auto result4{topKFrequent(nums4, 4)};

	print(result1);
	print(result2);
	print(result3);
	print(result4);
}
