#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    if(prices.size() == 1)
        return 0;
    
    int min{prices.at(0)};
    int max{prices.at(0)};
    int best_profit{};

    for(size_t i{}; i < prices.size() - 1; ++i)
    {
        if(prices.at(i) < min)
        {
            min = prices.at(i);
            max = prices.at(i);
        }
        if(prices.at(i+1) > max)
        {
            max = prices.at(i+1);
            if((max - min) > best_profit)
                best_profit = max - min;
        }
    }
    return best_profit;
}

int main()
{
    vector<int> prices{1,2};
    int result{maxProfit(prices)};

    cout << "Output: " << result << endl;
}
