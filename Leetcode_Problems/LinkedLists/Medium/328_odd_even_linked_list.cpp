#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // My Optimal Solution
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head;
        ListNode dummy;
        dummy.next = head;
        ListNode* left = head;
        ListNode* right = head->next;
        ListNode* node = head->next;
        while (left->next != nullptr && right->next != nullptr) {
            left->next = right->next;
            left = right->next;
            right->next = left->next;
            right = left->next;
        }
        left->next = node;
        return head;

        // Time Complexity - O(n) Space Complexity - 0(1)
    }
};