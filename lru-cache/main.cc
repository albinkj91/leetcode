#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    Node(int const val)
        :val{val}
    { }
    Node()
    { }

    Node* next{nullptr};
    Node* prev{nullptr};
    int val;
    int key;
};

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
            Node* tmp{map.at(key)};
            if(tmp->prev != nullptr)
            {
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
                tmp->next = nullptr;
                tail->next = tmp;
                tmp->prev = tail;
                tail = tail->next;
            }
            else if(tmp->next != nullptr)
            {
                head = tmp->next;
                tail->next = tmp;
                tmp->prev = tail;
                tail = tail->next;
                tail->next = nullptr;
            }
            return tmp->val;
        }
        return -1;
    }
    
    void put(int key, int value)
    {
        Node* node{new Node{value}};
        node->key = key;
        if(head == nullptr)
        {
            head = node;
            tail = node;
            --size;
        }
        else if(size > 0)
        {
            if(map.find(key) == map.end())
            {
                tail->next = node;
                node->prev = tail;
                tail = tail->next;
            }
            else
            {
                Node* tmp{map.at(key)};
                map.at(key) = node;
                if(tmp->prev != nullptr)
                {
                    tmp->prev->next = tmp->next;
                    tmp->next->prev = tmp->prev;
                    tail->next = node;
                    tail = tail->next;
                }
                else
                {
                    head = node;
                }
            }
            --size;
        }
        else
        {
            if(map.find(key) != map.end())
            {
                auto pos = map.find(key);
                map.erase(pos);
            }
            else
            {
                auto pos = map.find(head->key);
                map.erase(pos);
            }
            if(head->next != nullptr)
                head = head->next;
            if(head->prev != nullptr)
                head->prev = nullptr;
            tail->next = node;
            tail = tail->next;
        }
        map.emplace(key, node);
    }

    void print()
    {
        Node* tmp{head};
        while(tmp != nullptr)
        {
            cout << tmp->val << ',';
            tmp = tmp->next;
        }
        cout << endl;
    }
private:
    Node* head{new Node{}};
    Node* tail{new Node{}};
    unordered_map<int, Node*> map{};
    int size;
};

int main()
{
    LRUCache cache{2};
    cache.put(1,1);
    cache.put(2,2);
    cache.get(1);
    cache.put(3,3);
    cache.get(2);
    cache.put(4,4);
    cache.get(1);
    cache.get(3);
    cache.get(4);
    //cache.print();
}
