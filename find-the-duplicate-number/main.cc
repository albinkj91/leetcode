#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findDuplicate(vector<int>& nums)
{
    int slow{nums.at(0)};
    int fast{nums.at(nums.at(0))};

    while(slow != fast)
    {
        slow = nums.at(slow);
        fast = nums.at(nums.at(fast));
    }

    slow = fast;
    int slow2{};
    while(slow != slow2)
    {
        slow = nums.at(slow);
        slow2 = nums.at(slow2);
    }
    return slow;
}

int main()
{
    vector<int> nums1{1,3,4,2,2};
    vector<int> nums2{3,1,3,4,2};
    vector<int> nums3{3,3,3,3,3};

    cout << findDuplicate(nums1) << endl;
    cout << findDuplicate(nums2) << endl;
    cout << findDuplicate(nums3) << endl;
}
