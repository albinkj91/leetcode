#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if(nums.size() == 1)
        return vector<int>{1};
    vector<int> res{};
    map<int, int, greater<int>> m{};
    int len{static_cast<int>(nums.size())};

    if(k > 1)
    {
        for(int i{}; i < k-1; ++i)
            if(m.find(nums.at(i)) != m.end())
                ++m.at(nums.at(i));
            else
                m.emplace(nums.at(i), 1);
    }


    for(int i{k-1}; i < len; ++i)
    {
        if(m.find(nums.at(i)) != m.end())
            ++m.at(nums.at(i));
        else
            m.emplace(nums.at(i), 1);
        res.push_back(m.begin()->first);
        --m.at(nums.at(i-k+1));
        if(m.at(nums.at(i-k+1)) == 0)
            m.erase(nums.at(i-k+1));
    }
    return res;
}

int main()
{
    vector<int> nums{1,3,-1,-3,5,3,6,7};
    int k{3};
    vector<int> res{maxSlidingWindow(nums, k)};
    for(auto i : res)
        cout << i << " ";
    cout << endl;
}
