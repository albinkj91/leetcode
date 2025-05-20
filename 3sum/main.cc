#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <sstream>
#include <unordered_set>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums)
{
	vector<vector<int>> triplets{};
	sort(nums.begin(), nums.end());

	for(size_t i{}; i < nums.size(); ++i)
	{
		if(nums.at(i) > 0)
			break;
		if(i > 0 && nums.at(i) == nums.at(i - 1))
			continue;

		size_t j{i+1}, k{nums.size()-1};
		while(j < k)
		{
			int sum = nums.at(i) + nums.at(j) + nums.at(k);
			if(sum == 0)
			{
				triplets.push_back({nums.at(i), nums.at(j), nums.at(k)});
				++j;
				--k;
				while(j < k && nums.at(j) == nums.at(j-1))
					++j;
			}
			else if(sum < 0) // Increment middle pointer
			{
				++j;
			}
			else if(sum > 0) // Decrement end pointer
			{
				--k;
			}
		}
	}
	return triplets;
}

int main()
{
	vector<int> nums{-1,0,1,2,-1,-4};
	vector<vector<int>> triplets{threeSum(nums)};

	cout << '[';
	for(size_t i{}; i < triplets.size(); ++i)
	{
		cout << '[';
		for(size_t j{}; j < triplets.at(i).size(); ++j)
		{
			cout << triplets.at(i).at(j) << ',';
		}
		cout << "],";
	}
	cout << ']' << endl;
}
