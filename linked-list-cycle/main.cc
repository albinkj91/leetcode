#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool hasCycle(ListNode *head) {
    if(head == nullptr || head->next == nullptr)
        return false;
    
    while(head != nullptr)
    {
        if(head->val == 1000000)
            return true;
        else
            head->val = 1000000;
        head = head->next;
    }
    return false;
}

int main()
{
	struct ListNode* l4 = new ListNode{-4};
	struct ListNode* l3 = new ListNode{0, l4};
	struct ListNode* l2 = new ListNode{2, l3};
	struct ListNode* l1 = new ListNode{3, l2};
    l4->next = l2;
	bool result{hasCycle(l1)};
    cout << result << endl;

	delete l4;
	delete l3;
	delete l2;
	delete l1;
}
