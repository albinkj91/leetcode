#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* result{new ListNode{}};
    ListNode* tmp_result{result};
    ListNode* tmp1{l1};
    ListNode* tmp2{l2};
    int carry{};

    while(true)
    {
        int sum{};
        if(tmp1 == nullptr)
        {
            sum = tmp2->val + carry;
            tmp2 = tmp2->next;
        }
        else if(tmp2 == nullptr)
        {
            sum = tmp1->val + carry;
            tmp1 = tmp1->next;
        }
        else
        {
            sum = tmp1->val + tmp2->val + carry;
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }

        carry = sum > 9 ? 1 : 0;
        tmp_result->val = sum % 10;

        if(tmp1 == nullptr && tmp2 == nullptr)
        {
            if(carry == 1)
            {
                tmp_result->next = new ListNode{};
                tmp_result = tmp_result->next;
                tmp_result->val += 1;
            }
            break;
        }
        tmp_result->next = new ListNode{};
        tmp_result = tmp_result->next;
    }
    return result;
}

int main()
{
	struct ListNode* n7 = new ListNode{9};
	struct ListNode* n6 = new ListNode{9, n7};
	struct ListNode* n5 = new ListNode{9, n6};
	struct ListNode* n4 = new ListNode{9, n5};
	struct ListNode* n3 = new ListNode{9, n4};
	struct ListNode* n2 = new ListNode{9, n3};
	struct ListNode* n1 = new ListNode{9, n2};

	struct ListNode* n11 = new ListNode{9};
	struct ListNode* n10 = new ListNode{9, n11};
	struct ListNode* n9 = new ListNode{9, n10};
	struct ListNode* n8 = new ListNode{9, n9};

    ListNode* curr{addTwoNumbers(n1, n8)};

    while(curr != nullptr)
    {
        cout << "val: " << curr->val << endl;
        curr = curr->next;
    }

	delete n1;
	delete n2;
	delete n3;
	delete n4;
	delete n5;
	delete n6;
	delete n7;
	delete n8;
	delete n9;
	delete n10;
	delete n11;
    delete curr;
}
