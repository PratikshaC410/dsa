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
    int lenofll(Node *head, int key)
    {
        int cnt = 0;
        node *curr = head;
        while (curr != NULL)
        {
            cnt++;
            curr = curr->next;
        }
        return cnt;
    }
}