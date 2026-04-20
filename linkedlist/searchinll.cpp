#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(NULL) {}
}

class Soln
{
public:
    bool searchValue(Node *head, int key)
    {
        node *curr = head;
        while (curr != NULL)
        {
            if (curr.data == key)
                return true;
            curr = curr->next;
        }
        return false;
    }
}