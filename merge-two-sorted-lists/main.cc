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

	ListNode* curr1{list1};
	ListNode* curr2{list2};

	while(curr1 != nullptr || curr2 != nullptr)
	{
		if(curr1.val < curr2.val)
		{
			ListNode* temp = curr1->next;
			curr1->next = curr2;
			ListNode* temp2 = curr2->next;
		}
	}
	return head;
}

int main()
{
	struct ListNode* l6 = new ListNode{4};
	struct ListNode* l5 = new ListNode{3, l5};
	struct ListNode* l4 = new ListNode{1, l4};

	struct ListNode* l3 = new ListNode{4};
	struct ListNode* l2 = new ListNode{2, l3};
	struct ListNode* l1 = new ListNode{1, l2};
	reverseList(l1);

	delete l5;
	delete l4;
	delete l3;
	delete l2;
	delete l1;
}
