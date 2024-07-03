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
    ListNode *findMiddle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        ListNode *prev = nullptr;
        while (fast and fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev)
            prev->next = nullptr;

        return slow;
    }

    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        if (!head1)
            return head2;
        if (!head2)
            return head1;

        ListNode *new_head = nullptr;

        if (head1->val <= head2->val)
        {
            new_head = head1;
            head1 = head1->next;
        }
        else
        {
            new_head = head2;
            head2 = head2->next;
        }

        ListNode *temp = new_head;
        while (head1 or head2)
        {
            int val1 = INT_MAX, val2 = INT_MAX;

            if (head1)
                val1 = head1->val;
            if (head2)
                val2 = head2->val;

            if (val1 <= val2)
            {
                temp->next = head1;
                head1 = head1->next;
            }
            else
            {
                temp->next = head2;
                head2 = head2->next;
            }

            temp = temp->next;
        }

        return new_head;
    }

    // Time Complexity -> (2*n*(log(n))
    // Space Complexity -> O(log(n))
    ListNode *sortList(ListNode *head)
    {
        if (!head or !head->next)
            return head;

        ListNode *middle = findMiddle(head);

        ListNode *firstHalf = sortList(head);
        ListNode *secondHalf = sortList(middle);

        return merge(firstHalf, secondHalf);
    }
};

int main()
{

    return 0;
}