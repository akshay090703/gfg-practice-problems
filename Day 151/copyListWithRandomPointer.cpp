#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *newHead = nullptr;
        Node *temp = head;
        Node *link = nullptr;
        unordered_map<Node *, Node *> mp;
        while (temp)
        {
            Node *newNode = new Node(temp->val);

            if (link)
                link->next = newNode;
            if (!newHead)
                newHead = newNode;

            mp[temp] = newNode;
            link = newNode;
            temp = temp->next;
        }

        temp = head;
        Node *newTemp = newHead;
        while (newTemp)
        {
            if (temp->random)
            {
                newTemp->random = mp[temp->random];
            }

            temp = temp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};

// Another approach with O(1) space complexity
// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         if(!head) return head;

//         Node* temp = head;
//         while(temp) {
//             Node* newNode = new Node(temp->val);

//             Node *nextNode = temp->next;
//             temp->next = newNode;
//             newNode->next = nextNode;
//             temp = nextNode;
//         }

//         temp = head;
//         while(temp) {
//             if(temp->random) temp->next->random = temp->random->next;
//             temp = temp->next->next;
//         }

//         temp = head;
//         Node *new_head = nullptr;
//         Node *prev = nullptr;
//         while(temp) {
//             Node *listNode = temp->next;
//             if(!new_head) new_head = listNode;

//             temp->next = temp->next->next;

//             if(prev) {
//                 prev->next = listNode;
//             }

//             prev = listNode;
//             temp = temp->next;
//         }

//         return new_head;
//     }
// };

int main()
{

    return 0;
}