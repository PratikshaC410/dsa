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

void insertAtEnd(Node *&head, int val)
{
    Node *curr = head;
    Node *newnode = new Node(val);
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    if (curr->next == NULL)
    {
        curr->next = newnode;
        return head;
    }
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newnode;
    retunr head;
}