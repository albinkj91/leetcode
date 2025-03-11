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

ListNode* reverseList(ListNode* head) {
	if(head == nullptr || head->next == nullptr)
		return head;

	struct ListNode* t1{head};
	struct ListNode* t2{head->next};

	head = t2->next;
	t1->next = nullptr;
	t2->next = t1;

	if(head == nullptr)
		return t2;

	while(head->next != nullptr)
	{
		t1 = t2;
		t2 = head;
		head = head->next;

		t2->next = t1;
	}
	head->next = t2;
	return head;
}

int main()
{
	struct ListNode* l5 = new ListNode{5};
	struct ListNode* l4 = new ListNode{4, l5};
	struct ListNode* l3 = new ListNode{3, l4};
	struct ListNode* l2 = new ListNode{2, l3};
	struct ListNode* l1 = new ListNode{1, l2};
	reverseList(l1);

	delete l5;
	delete l4;
	delete l3;
	delete l2;
	delete l1;
}
