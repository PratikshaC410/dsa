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

Node *deletelastnode(Node *&head, int val)
{
    Node *curr = head;
    Node *prev1 = head->prev;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    while (curr->next != NULL)
    {
        prev1 = prev1->next;
        curr = curr->next;
    }
    prev1->next = NULL;
    curr->prev = NULL;
    delete curr;
    return head;
}