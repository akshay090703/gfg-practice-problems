#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    int getNthFromLast(Node *head, int n)
    {
        if (!head)
            return -1;

        int count = 0;
        Node *temp = head;
        while (temp)
        {
            count++;
            temp = temp->next;
        }

        if (count < n)
            return -1;

        int i = 0;
        Node *kthNode = head;
        while (i < (count - n))
        {
            kthNode = kthNode->next;
            i++;
        }

        return kthNode->data;
    }
};

int main()
{

    return 0;
}