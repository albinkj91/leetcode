#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    if(s.length() == 0)
        return 0;
    if(s.length() == 1)
        return 1;

    unordered_set<char> doubles{s.at(0)};
    size_t longest{};
    size_t l{};
    size_t r{};
    while(++r < s.length())
    {
        while(doubles.find(s.at(r)) != doubles.end())
        {
            doubles.erase(s.at(l));
            ++l;
        }
        doubles.emplace(s.at(r));
        longest = max(longest, r-l+1);
    }
    return longest;
}

int main()
{
    string s{"au"};
    int res{lengthOfLongestSubstring(s)};
    cout << "Result: " << res << endl;
}
