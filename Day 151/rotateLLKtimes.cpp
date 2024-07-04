#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    pair<ListNode *, ListNode *> reverseLL(ListNode *head, int k)
    {
        ListNode *prev = nullptr, *curr = head, *next = nullptr;
        for (int i = 0; i < k; i++)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return {prev, next};
    }

    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || k == 0)
            return head;

        int count = 0;
        ListNode *temp = head;
        while (temp)
        {
            count++;
            temp = temp->next;
        }
        k %= count;
        if (k == 0)
            return head;

        pair<ListNode *, ListNode *> p = reverseLL(head, count - k);
        pair<ListNode *, ListNode *> q = reverseLL(p.second, k);

        head->next = q.first;

        pair<ListNode *, ListNode *> ans = reverseLL(p.first, count);
        return ans.first;
    }
};

int main()
{

    return 0;
}