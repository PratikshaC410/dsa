#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{

    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int floorInBST(TreeNode *root, int key)
    {

        int floor = -1;

        while (root)
        {
            if (root->val == key)
            {
                floor = root->val;
                return floor;
            }

            if (key > root->val)
            {
                floor = root->val;
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }
        return floor;
    }
};

void printInOrder(TreeNode *root)
{

    if (root == nullptr)
        return;

    printInOrder(root->left);

    cout << root->val << " ";

    printInOrder(root->right);
}
