#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    int largest{};

    for(int i : piles)
        largest = std::max(largest, i);

    int l{1};
    int r{largest};
    int mid{r/2};
    int k{numeric_limits<int>::max()};
    int len{static_cast<int>(piles.size())};

    while(l <= r)
    {
        int curr{};
        for(int i : piles)
            curr += ceil(i/static_cast<double>(mid));

        if(mid < k && curr >= len && curr <= h)
            k = mid;

        if(curr > h)
            l = mid + 1;
        else if(curr <= h)
            r = mid - 1;
        mid = (r+l) / 2;
    }
    return k;
}

int main()
{
    vector<int> piles{1000000000};
    int h{2};
    int res{minEatingSpeed(piles, h)};
    cout << "Result: " << res << '\n' << endl;
}
