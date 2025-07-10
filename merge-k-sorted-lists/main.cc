#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
ListNode* mergeKLists(vector<ListNode*>& lists) {
    vector<pair<int, ListNode*>> buckets(20000, pair<int, ListNode*>{0, nullptr});
    for(auto const& l : lists)
    {
        ListNode* tmp{l};
        while(tmp != nullptr)
        {
            ++buckets.at(tmp->val + 10000).first;
            buckets.at(tmp->val + 10000).second = tmp;
            tmp = tmp->next;
        }
    }

    ListNode* result{new ListNode{}};
    ListNode* tmp{result};
    for(size_t i{}; i < buckets.size(); ++i)
    {
        if(buckets.at(i).first > 0)
        {
            for(int j{}; j < buckets.at(i).first; ++j)
            {
                tmp->next = new ListNode{*buckets.at(i).second};
                tmp = tmp->next;
            }
        }
    }
    result = result->next;
    return result;
}

void print(ListNode* list)
{
    ListNode* tmp{list};
    while(tmp != nullptr)
    {
        cout << tmp->val << ',';
        tmp = tmp->next;
    }
    cout << endl;
}

int main()
{
    ListNode* n1{new ListNode{5}};
    ListNode* n2{new ListNode{4, n1}};
    ListNode* n3{new ListNode{1, n2}};

    ListNode* n4{new ListNode{4}};
    ListNode* n5{new ListNode{3, n4}};
    ListNode* n6{new ListNode{1, n5}};

    ListNode* n7{new ListNode{6}};
    ListNode* n8{new ListNode{2, n7}};

    vector<ListNode*> lists{n8, n6, n3};

    ListNode* result{mergeKLists(lists)};
    print(result);
}
