#include <iostream>
#include <unordered_map>
using namespace std;

int characterReplacement(string s, int k)
{
    int l{};
    int max_freq{};
    int longest{};
    int len{static_cast<int>(s.length())};
    unordered_map<char, int> freq{};

    for(int i{}; i < len; ++i)
    {
        if(freq.find(s.at(i)) != freq.end())
            ++freq.at(s.at(i));
        else
            freq.emplace(s.at(i), 1);

        max_freq = max(max_freq, freq.at(s.at(i)));
        while((i-l+1) - max_freq > k)
            --freq.at(s.at(l++));
        longest = max(longest, i-l+1);
    }
    return longest;
}

int main()
{
    string s{"ABAB"};
    int k{2};
    int res{characterReplacement(s, k)};
    cout << "Result: " << res << endl;
}
