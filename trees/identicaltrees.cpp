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
    bool isIdentical(Node *node1, Node *node2)
    {
        if (node1 == NULL && node2 == NULL)
        {
            return true;
        }
        if (node1 == NULL || node2 == NULL)
        {
            return false;
        }

        return ((node1->data == node2->data) && isIdentical(node1->left, node2->left) && isIdentical(node1->right, node2->right));
    }
};
