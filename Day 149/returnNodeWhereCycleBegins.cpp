#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;

        while (fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                ListNode *temp = head;

                while (temp != slow)
                {
                    temp = temp->next;
                    slow = slow->next;
                }

                return slow;
            }
        }

        return nullptr;
    }
};

int main()
{

    return 0;
}