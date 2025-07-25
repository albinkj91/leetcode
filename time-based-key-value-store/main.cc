#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class TimeMap
{
public:
    string binary_search(vector<pair<int, string>> const& timestamps, int const key)
    {
        int l{};
        int r{static_cast<int>(timestamps.size())-1};
        int mid{r/2};

        while(l <= r)
        {
            if(timestamps.at(mid).first == key)
                return timestamps.at(mid).second;
            else if(key < timestamps.at(mid).first)
                r = mid - 1;
            else if(key > timestamps.at(mid).first)
                l = mid + 1;
            mid = (l+r) / 2;
        }
        if(mid >= 0 && timestamps.at(mid).first < key)
            return timestamps.at(mid).second;
        return "";
    }

    void set(string key, string value, int timestamp)
    {
        if(map.find(key) == map.end())
            map.emplace(key, vector<pair<int, string>>{});
        map.at(key).push_back(pair<int, string>{timestamp, value});
    }
    
    string get(string key, int timestamp)
    {
        if(map.find(key) != map.end())
            return binary_search(map.at(key), timestamp);
        return "";
    }

private:
    unordered_map<string, vector<pair<int, string>>> map{};
};

int main()
{
    TimeMap* timeMap{new TimeMap()};
    timeMap->set("love", "high", 10);
    timeMap->set("love", "low", 20);
    cout << timeMap->get("love", 5) << endl;
    cout << timeMap->get("love", 10) << endl;
    cout << timeMap->get("love", 15) << endl;
    cout << timeMap->get("love", 20) << endl;
    cout << timeMap->get("love", 25) << endl;
}
