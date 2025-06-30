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

void reorderList(ListNode* head) {
    if(head == nullptr || head->next == nullptr)
        return;

    vector<ListNode*> nodes{};
    ListNode* curr{head->next};
    while(curr != nullptr)
    {
        nodes.push_back(curr);
        curr = curr->next;
    }

    curr = head;
    int size{static_cast<int>(nodes.size())};

    for(int i{size-1}; i >= size/2; i--)
    {
        ListNode* tmp{curr->next};
        curr->next = nodes.at(i);
        nodes.at(i)->next = tmp;
        curr = nodes.at(i)->next;
    }

    curr->next = nullptr;
}

int main()
{
	struct ListNode* l4 = new ListNode{4};
	struct ListNode* l3 = new ListNode{3, l4};
	struct ListNode* l2 = new ListNode{2, l3};
	struct ListNode* l1 = new ListNode{1, l2};
    reorderList(l1);

    ListNode* curr{l1};
    while(curr != nullptr)
    {
        cout << curr->val << endl;
        curr = curr->next;
    }

	delete l4;
	delete l3;
	delete l2;
	delete l1;
}
