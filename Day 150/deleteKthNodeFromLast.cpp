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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *slow = head, *fast = head;
        int diff = 1;
        while (diff < n and fast->next)
        {
            diff++;
            fast = fast->next;
        }

        if (!fast->next)
        {
            ListNode *new_head = head->next;
            delete head;
            return new_head;
        }

        ListNode *prev = nullptr;
        while (fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *toBeDeleted = slow;
        if (toBeDeleted->next)
        {
            prev->next = toBeDeleted->next;
        }
        else
        {
            prev->next = nullptr;
        }

        delete toBeDeleted;
        return head;
    }
};

int main()
{

    return 0;
}