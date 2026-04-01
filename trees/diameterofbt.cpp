
#include <iostream>
#include <algorithm>

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
    int diameterOfBinaryTree(Node *root)
    {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

private:
    int height(Node *node, int &diameter)
    {
        if (!node)
        {
            return 0;
        }
        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);

        diameter = max(diameter, lh + rh);

        return 1 + max(lh, rh);
    }
};
