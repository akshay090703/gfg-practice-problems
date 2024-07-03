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
    ListNode *deleteMiddle(ListNode *head)
    {
        if (!head->next)
            return nullptr;

        ListNode *slow = head, *fast = head;
        ListNode *prev = nullptr;
        while (fast and fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (slow->next)
        {
            prev->next = slow->next;
        }
        else
        {
            prev->next = nullptr;
        }

        delete slow;
        return head;
    }
};

int main()
{

    return 0;
}