#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

Node *reversedll(Node *&head, int val)
{
    Node *curr = head;

    while (curr != NULL)
    {
        Node *temp = curr->next;
        curr->next = curr->back;
        curr->back = temp;

        head = curr;
        curr = temp;
    }

    return head;
}