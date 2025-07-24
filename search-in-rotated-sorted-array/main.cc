#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target)
{
    int l{};
    int r{static_cast<int>(nums.size())-1};

    while(l <= r)
    {
        int mid{(l+r) / 2};
        if(nums.at(mid) == target)
            return mid;
        else if(nums.at(l) <= nums.at(mid))
        {
            if(target < nums.at(mid) && target >= nums.at(l))
                r = mid - 1;
            else
                l = mid + 1;
        }
        else
        {
            if(target > nums.at(mid) && target <= nums.at(r))
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums{4,5,6,7,0,1,2};
    int target{3};
    int res{search(nums, target)};
    cout << "Result: " << res << '\n' << endl;
}
