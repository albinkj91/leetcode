#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <map>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k)
{
	if(nums.size() == 1)
		return vector<int>{nums.at(0)};
	unordered_map<int, int> hmap{};

	for(size_t i{0}; i < nums.size(); ++i)
	{
		if(hmap.find(nums.at(i)) != hmap.end())
			hmap.at(nums.at(i))++;
		else
			hmap.emplace(nums.at(i), 1);
	}

	vector<vector<int>> freq(nums.size());
	for_each(hmap.begin(), hmap.end(),
			[&freq](pair<int, int> p)
			{
				freq.at(p.second-1).push_back(p.first);
			});

	vector<int> result{};
	for(auto i{freq.size()-1}; k > 0; --i)
	{
		for(unsigned j{}; j < freq.at(i).size() && k > 0; ++j)
		{
			result.push_back(freq.at(i).at(j));
			--k;
		}
	}
	return result;
}

void print(vector<int> result)
{
	copy(result.begin(), result.end(),
			ostream_iterator<int>{cout, " "});
	cout << endl;
}

int main()
{
	vector<int> nums1{7,7};
	vector<int> nums2{1,2};
	vector<int> nums3{1,2,2,3,3,3};
	auto result1{topKFrequent(nums1, 1)};
	auto result2{topKFrequent(nums2, 2)};
	auto result3{topKFrequent(nums3, 2)};

	print(result1);
	print(result2);
	print(result3);
}
