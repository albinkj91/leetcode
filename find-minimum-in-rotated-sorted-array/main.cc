#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

int findMin(vector<int>& nums)
{
    int l{};
    int r{static_cast<int>(nums.size()) - 1};
    int mid{r/2};
    int res{nums.at(0)};

    while(l <= r)
    {
        if(nums.at(l) < nums.at(r) || r == 0)
            return min(res, nums.at(l));

        if(nums.at(mid) >= nums.at(l))
            l = mid + 1;
        else
            r = mid - 1;
        res = min(res, nums.at(mid));
        mid = (r+l) / 2;
    }
    return res;
}

int main()
{
    vector<int> nums{11,13,15,17};
    int res{findMin(nums)};
    cout << "Result: " << res << endl;
}
