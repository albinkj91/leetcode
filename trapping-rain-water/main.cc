#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& height)
{
	if(height.empty())
		return 0;

	int l{};
	int r{static_cast<int>(height.size() - 1)};
	int l_max{height.at(l)};
	int r_max{height.at(r)};
	int amount{};

	while(l < r)
	{
		if(l_max < r_max)
		{
			++l;
			l_max = max(l_max, height.at(l));
			amount += l_max - height.at(l);
		}
		else
		{
			--r;
			r_max = max(r_max, height.at(r));
			amount += r_max - height.at(r);
		}
	}
	return amount;
}

int main()
{
	vector<int> h1{0,1,0,2,1,0,1,3,2,1,2,1};

	int amount{trap(h1)};
	cout << "Amount: " << amount << endl;
}
