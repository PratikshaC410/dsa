#include <bits/stdc++.h>
using namespace std;

// define tree node structure
struct TreeNode
{
    // value of the node
    int val;
    // pointer to left child
    TreeNode *left;
    // pointer to right child
    TreeNode *right;
    // constructor
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// solution class
class Solution
{
public:
    // find inorder successor iteratively
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        // initialize successor
        TreeNode *successor = nullptr;
        // traverse until root becomes null
        while (root != nullptr)
        {
            // when p is greater or equal, move right
            if (p->val >= root->val)
            {
                root = root->right;
            }
            // otherwise update successor and move left
            else
            {
                successor = root;
                root = root->left;
            }
        }
        // return successor (may be null)
        return successor;
    }
};

// inorder print helper
void printInOrder(TreeNode *root)
{
    // base case
    if (root == nullptr)
        return;
    // traverse left
    printInOrder(root->left);
    // print node
    cout << root->val << " ";
    // traverse right
    printInOrder(root->right);
}
