#include <bits/stdc++.h>
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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr, *curr = head, *next = nullptr;

        while (curr)
        {
            next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

// Using Recursion
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         // Base: if there is only 1 node or no node, LL is already reversed
//         if(!head or !head->next) return head;

//         // reverse the rest of the linked list
//         ListNode *rest = reverseList(head->next);

//         // put the first node at the end
//         head->next->next = head;
//         head->next = nullptr;

//         // return the reversed head;
//         return rest;
//     }
// };

int main()
{

    return 0;
}