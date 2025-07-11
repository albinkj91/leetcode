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

ListNode* reverseKGroup(ListNode* head, int k) {
    if(k == 1)
        return head;

    ListNode* sentinel{new ListNode{0, head}};
    ListNode* left{sentinel};
    ListNode* curr{head};
    ListNode* tmp{head};

    while(tmp != nullptr)
    {
        int count{k};
        while(count-- > 0 && tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        if(count > 0)
            break;
        count = 1;
        while(count++ < k)
        {
            curr = head->next;
            head->next = curr->next;
            curr->next = left->next;
            left->next = curr;
        }
        tmp = head->next;
        left = head;
        head = tmp;
    }
    left = sentinel->next;
    delete sentinel;
    return left;
}

int main()
{
    ListNode* n6{new ListNode{6}};
    ListNode* n5{new ListNode{5, n6}};
    ListNode* n4{new ListNode{4, n5}};
    ListNode* n3{new ListNode{3, n4}};
    ListNode* n2{new ListNode{2, n3}};
    ListNode* n1{new ListNode{1, n2}};

    ListNode* result{reverseKGroup(n1, 2)};
    print(result);
}
