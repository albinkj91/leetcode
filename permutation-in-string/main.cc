#include <string>
#include <iostream>
#include <vector>
using namespace std;

bool checkInclusion(string s1, string s2) {
    int win_size{static_cast<int>(s1.length())};
    int s2_len{static_cast<int>(s2.length())};
    vector<int> freq(26, 0);

    for(int i{}; i < win_size; ++i)
        ++freq.at(s1.at(i) - 'a');

    for(int i{}; i < (s2_len - win_size+1); ++i)
    {
        vector<int> copy_freq{freq};
        for(int j{i}; j < i+win_size; ++j)
            --copy_freq.at(s2.at(j) - 'a');

        bool permutation_exists{true};
        for(int const count : copy_freq)
            if(count != 0)
                permutation_exists = false;
        if(permutation_exists)
            return true;
    }
    return false;
}

int main()
{
    string s1{"hello"};
    string s2{"ooolleooolleh"};
    int res{checkInclusion(s1, s2)};
    cout << "Result: " << res << endl;
}
