#include <iostream>

struct ListNode
{
    int data;
    ListNode *next;
};

ListNode *
removeNthFromEnd(ListNode *head, int n)
{
    ListNode **t1 = &head, *t2 = head;
    for (int i = 1; i < n; ++i)
    {
        t2 = t2->next;
    }
    while (t2->next != NULL)
    {
        t1 = &((*t1)->next);
        t2 = t2->next;
    }
    *t1 = (*t1)->next;
    return head;
}

int main()
{
    ListNode *node, *tmp, *head;
    node = new ListNode;
    node->data = 1;
    tmp = node;
    head = node;
    node = new ListNode;
    node->data = 5;
    tmp->next = node;
    tmp = tmp->next;
    node = new ListNode;
    node->data = 8;
    tmp->next = node;
    tmp = tmp->next;
    node->next = NULL;
    ListNode *res;
    res = removeNthFromEnd(head, 1);
}