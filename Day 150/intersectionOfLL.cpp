#include <iostream>
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *temp1 = headA;
        int count1 = 0;
        ListNode *temp2 = headB;
        int count2 = 0;
        while (temp1 or temp2)
        {
            if (temp1)
            {
                count1++;
                temp1 = temp1->next;
            }

            if (temp2)
            {
                count2++;
                temp2 = temp2->next;
            }
        }

        temp1 = headA, temp2 = headB;
        int diff = abs(count1 - count2);
        if (count1 > count2)
        {
            while (diff--)
            {
                temp1 = temp1->next;
            }
        }
        else
        {
            while (diff--)
            {
                temp2 = temp2->next;
            }
        }

        while (temp1 and temp2 and temp1 != temp2)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        if (!temp1 or !temp2)
            return nullptr;

        return temp1;
    }
};

int main()
{

    return 0;
}