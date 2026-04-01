
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int maxDepth(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int lh = maxDepth(root->left);

        int rh = maxDepth(root->right);

        return 1 + max(lh, rh);
    }
};
