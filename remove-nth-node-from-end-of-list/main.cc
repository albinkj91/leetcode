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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head->next == nullptr)
    {
        head = nullptr;
        return head;
    }

    vector<ListNode*> nodes{};
    ListNode* curr{head};

    int count{};
    while(curr != nullptr)
    {
        nodes.push_back(curr);
        curr = curr->next;
        ++count;
    }
    int index{count - n};
    if(nodes.size() < 3)
    {
        head = nodes.at(n-1);
        head->next = nullptr;
    }
    else if((count - index) == 1)
    {
        nodes.at(index-1)->next = nullptr;
    }
    else if(index == 0)
    {
        head = nodes.at(index+1);
    }
    else
        nodes.at(index-1)->next = nodes.at(index+1);
    return head;
}

int main()
{
	struct ListNode* l3 = new ListNode{3};//, l4};
	struct ListNode* l2 = new ListNode{2, l3};
	struct ListNode* l1 = new ListNode{1, l2};

    ListNode* curr{removeNthFromEnd(l1, 3)};

    while(curr != nullptr)
    {
        cout << curr->val << endl;
        curr = curr->next;
    }

	delete l3;
	delete l2;
	delete l1;
}
