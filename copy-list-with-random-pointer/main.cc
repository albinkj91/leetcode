#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    if(head == nullptr)
        return nullptr;
    unordered_map<Node*, Node*> map{};
    Node* tmp{head};
    Node* copy{new Node{head->val}};
    Node* copy_tmp{copy};
    map.emplace(head, copy);

    while(tmp != nullptr)
    {
        copy_tmp->val = tmp->val;
        if(tmp->next == nullptr)
            copy_tmp->next = nullptr;
        else
            copy_tmp->next = new Node{tmp->next->val};
        map.emplace(tmp, copy_tmp);
        copy_tmp = copy_tmp->next;
        tmp = tmp->next;
    }

    copy_tmp = copy;
    tmp = head;
    while(tmp != nullptr)
    {
        if(map.find(tmp->random) != map.end())
        {
            copy_tmp->random = map.at(tmp->random);
        }
        else
        {
            copy_tmp->random = nullptr;
        }
        copy_tmp = copy_tmp->next;
        tmp = tmp->next;
    }
    return copy;
}


int main()
{
	struct Node* n1 = new Node{7};
	struct Node* n2 = new Node{13};
	struct Node* n3 = new Node{11};
	struct Node* n4 = new Node{10};
	struct Node* n5 = new Node{1};

    n1->next = n2;
    n1->random = nullptr;
    n2->next = n3;
    n2->random = n1;
    n3->next = n4;
    n3->random = n5;
    n4->next = n5;
    n4->random = n3;
    n5->next = nullptr;
    n5->random = n1;

    Node* curr{copyRandomList(n1)};

	delete n1;
	delete n2;
	delete n3;
	delete n4;
	delete n5;

    while(curr != nullptr)
    {
        if(curr->random == nullptr)
            cout << "val: " << curr->val << "\trandom: null" << endl;
        else
            cout << "val: " << curr->val << "\trandom: " << curr->random->val << endl;
        Node* tmp{curr};
        curr = curr->next;
        delete tmp;
    }
    delete curr;
}
