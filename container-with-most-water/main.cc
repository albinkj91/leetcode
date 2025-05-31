#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
	int max{};
	int left{};
	int right{static_cast<int>(height.size()-1)};

	while(left != right)
	{
		int current{};
		if(height.at(left) > height.at(right))
		{
			current = height.at(right) * (right-left);
			--right;
		}
		else
		{
			current = height.at(left) * (right-left);
			++left;
		}
		if(current > max)
			max = current;
	}
	return max;
}

int main()
{
	vector<int> height{1,8,6,2,5,4,8,3,7};

	int amount{maxArea(height)};
	cout << amount << endl;
}
