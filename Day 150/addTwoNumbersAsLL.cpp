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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (!l2)
            return l1;
        if (!l1)
            return l2;

        int carry = 0;
        ListNode *head = nullptr;
        ListNode *temp = nullptr;
        while (l1 or l2)
        {
            int firstNum = 0, secondNum = 0;

            if (l1)
                firstNum = l1->val;
            if (l2)
                secondNum = l2->val;

            int sum = firstNum + secondNum + carry;
            carry = sum / 10;
            int digit = sum % 10;

            ListNode *newNode = new ListNode(digit);

            if (!head)
            {
                head = newNode;
                temp = head;
            }
            else
            {
                temp->next = newNode;
                temp = temp->next;
            }

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }

        if (carry > 0)
        {
            ListNode *newNode = new ListNode(carry);
            temp->next = newNode;
        }

        return head;
    }
};

int main()
{

    return 0;
}