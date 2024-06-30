#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        if (!node or !node->next)
            return;

        node->val = node->next->val;

        ListNode *temp = node->next;
        node->next = temp->next;

        delete temp;
    }
};

int main()
{

    return 0;
}