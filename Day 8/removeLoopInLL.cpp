#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Solution
{
public:
    // Function to remove a loop in the linked list
    //  Using Floyd's Algorithm
    void removeLoop(Node *head)
    {
        Node *slow = head;
        Node *fast = head;
        Node *prev = nullptr;

        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;

            // loop is detected
            if (slow == fast)
            {
                Node *temp = head;

                // when the loop is formed at the head node itself
                if (slow == head)
                {
                    prev->next = nullptr;
                    return;
                }

                // to find which node to choose to point nullptr
                while (temp->next != slow->next)
                {
                    temp = temp->next;
                    slow = slow->next;
                }

                // pointing to nullptr and breaking the loop
                slow->next = nullptr;
                return;
            }
        }
    }
};

int main()
{

    return 0;
}