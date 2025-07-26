#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int goLeft(TreeNode* left)
{
    if(left == nullptr)
        return 0;
    else if(left->left == nullptr && left->right != nullptr)
        return 1 + goLeft(left->right);
    return 1 + goLeft(left->left);
}

int goRight(TreeNode* right)
{
    if(right == nullptr)
        return 0;
    else if(right->right == nullptr && right->left != nullptr)
        return 1 + goRight(right->left);
    return 1 + goRight(right->right);
}

int diameterOfBinaryTree(TreeNode* root) {
    if(root == nullptr)
        return 0;
    return goLeft(root->left) + goRight(root->right);
}

int main()
{
    //TreeNode* t5{new TreeNode{5}};
    //TreeNode* t4{new TreeNode{4}};
    //TreeNode* t3{new TreeNode{3}};
    //TreeNode* t2{new TreeNode{2, t4, t5}};
    //TreeNode* t1{new TreeNode{1, t2, t3}};

    //int res{diameterOfBinaryTree(t1)};
    //cout << "Result: " << res << endl;

    //TreeNode* t2{new TreeNode{2}};
    //TreeNode* t1{new TreeNode{1, t2, nullptr}};

    //int res{diameterOfBinaryTree(t1)};
    //cout << "Result: " << res << endl;

    //TreeNode* t3{new TreeNode{2}};
    //TreeNode* t2{new TreeNode{1, nullptr, t3}};
    //TreeNode* t1{new TreeNode{3, t2, nullptr}};

    //int res{diameterOfBinaryTree(t1)};
    //cout << "Result: " << res << endl;
    //
    TreeNode* t5{new TreeNode{5}};
    TreeNode* t4{new TreeNode{1, t5, nullptr}};
    TreeNode* t3{new TreeNode{3, nullptr, nullptr}};
    TreeNode* t2{new TreeNode{2, t3, t4}};
    TreeNode* t1{new TreeNode{4, t2, nullptr}};

    int res{diameterOfBinaryTree(t1)};
    cout << "Result: " << res << endl;
}
