#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode()
		:val(0), next(nullptr)
	{}

    ListNode(int x)
		: val(x), next(nullptr) {}

    ListNode(int x, ListNode *next)
		: val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
	if(list1 == nullptr)
		return list2;
	else if(list2 == nullptr)
		return list1;

    ListNode* head = new ListNode{};
    ListNode* curr_head = head;
	ListNode* curr1{list1};
	ListNode* curr2{list2};

	while(!(curr1 == nullptr && curr2 == nullptr))
	{
        if(curr1 == nullptr)
        {
            curr_head->val = curr2->val;
            if(curr2->next == nullptr)
                curr2 = nullptr;
            else
                curr2 = curr2->next;
        }
        else if(curr2 == nullptr)
        {
            curr_head->val = curr1->val;
            if(curr1->next == nullptr)
                curr1 = nullptr;
            else
                curr1 = curr1->next;
        }
        else if(curr1->val < curr2->val)
		{
            curr_head->val = curr1->val;
            if(curr1->next == nullptr)
                curr1 = nullptr;
            else
                curr1 = curr1->next;
		}
        else
        {
            curr_head->val = curr2->val;
            if(curr2->next == nullptr)
                curr2 = nullptr;
            else
                curr2 = curr2->next;
        }
        if(curr1 != nullptr || curr2 != nullptr)
        {
            curr_head->next = new ListNode{};
            curr_head = curr_head->next;
        }
	}
	return head;
}

int main()
{
	struct ListNode* l6 = new ListNode{4};
	struct ListNode* l5 = new ListNode{3, l6};
	struct ListNode* l4 = new ListNode{1, l5};

	struct ListNode* l3 = new ListNode{4};
	struct ListNode* l2 = new ListNode{2, l3};
	struct ListNode* l1 = new ListNode{1, l2};
	ListNode* merged{mergeTwoLists(l1, l4)};

	delete l6;
	delete l5;
	delete l4;
	delete l3;
	delete l2;
	delete l1;
    delete merged;
}
