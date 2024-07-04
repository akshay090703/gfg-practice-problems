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

// My approach
class Solution
{
public:
    pair<ListNode *, ListNode *> reverseGroup(ListNode *head, int k)
    {
        ListNode *prev = nullptr, *curr = head, *next = nullptr;
        while (k--)
        {
            next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return {prev, next};
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k == 1)
            return head;

        ListNode *temp = head;
        int count = 0;
        while (temp)
        {
            temp = temp->next;
            count++;
        }

        int reverses = count / k;
        temp = head;
        ListNode *new_head = nullptr;
        ListNode *lastTail = nullptr;
        while (reverses--)
        {
            pair<ListNode *, ListNode *> p = reverseGroup(temp, k);

            ListNode *reversed_head = p.first;
            ListNode *nextNode = p.second;

            if (!new_head)
            {
                new_head = reversed_head;
            }

            if (lastTail)
                lastTail->next = reversed_head;

            lastTail = temp;
            temp = nextNode;
        }

        if (temp)
        {
            lastTail->next = temp;
        }

        return new_head;
    }
};

// Using Recursion
// class Solution {
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         if(k == 1) return head;

//         ListNode* node = head;
//         for(int i = 0; i<k; i++) {
//             if(!node) return head;

//             node = node->next;
//         }

//         ListNode *prev = nullptr, *curr = head, *next = nullptr;
//         for(int i = 0; i<k; i++) {
//             next = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = next;
//         }

//         head->next = reverseKGroup(next, k);

//         return prev;
//     }
// };

int main()
{

    return 0;
}