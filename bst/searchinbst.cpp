#include <bits/stdc++.h>
using namespace std;

// Definition of TreeNode
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        val = data;
        left = right = nullptr;
    }
};

class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int target)
    {

        while (root != nullptr && root->val != target)
        {

            if (target < root->val)
            {
                root = root->left;
            }

            else
            {
                root = root->right;
            }
        }

        return root;
    }
};
