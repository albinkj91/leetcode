#include <iostream>
#include <unordered_map>
#include <list>
#include <iterator>
using namespace std;

class LRUCache
{
public:
    LRUCache(int capacity)
        :size(capacity)
    { }
    
    int get(int key)
    {
        if(map.find(key) != map.end())
        {
            values.erase(map.at(key).second);
            values.push_back(key);
            auto test{--values.end()};
            map.at(key).second = test;
            return map.at(key).first;
        }
        return -1;
    }
    
    void put(int key, int value)
    {
        if(map.find(key) != map.end())
        {
            values.erase(map.at(key).second);
            map.erase(key);
        }
        else if(static_cast<int>(map.size()) == size)
        {
            int lru{values.front()};
            values.pop_front();
            map.erase(lru);
        }
        values.push_back(key);
        map.emplace(key, pair<int, list<int>::iterator>{value, --values.end()});
    }
private:
    list<int> values{};
    unordered_map<int, pair<int, list<int>::iterator>> map{};
    int size;
};

int main()
{
    LRUCache cache2{2};
    cache2.put(2,1);
    cache2.put(2,2);
    cout << cache2.get(2) << endl;
    cache2.put(1,1);
    cache2.put(4,1);
    cout << cache2.get(2) << endl;
}
