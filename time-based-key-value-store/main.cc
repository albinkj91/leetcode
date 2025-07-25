#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class TimeMap
{
public:
    void set(string key, string value, int timestamp)
    {
        if(map.find(key) != map.end())
        {
            map.at(key).emplace(timestamp, value);
        }
        else
        {
            map.emplace(key, unordered_map<int, string>{});
            map.at(key).emplace(timestamp, value);
        }
    }
    
    string get(string key, int timestamp)
    {
        if(map.find(key) != map.end())
        {
            if(map.at(key).find(timestamp) != map.at(key).end())
                return map.at(key).at(timestamp);
            else
                return map.at(key).begin()->second;
        }
        return "";
    }

private:
    unordered_map<string, unordered_map<int, string>> map{};
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
