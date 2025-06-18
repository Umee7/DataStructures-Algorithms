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
    ListNode* deleteMiddle(ListNode* head) {
        // My optimal solution
        // ListNode *slow = head;
        // ListNode *fast = head;
        // if(slow->next == nullptr) return nullptr;
        // if(slow->next->next == nullptr) {
        //     slow->next = nullptr;
        //     return head;
        // }
        // while(fast != nullptr && fast->next != nullptr) {
        //     slow = slow->next;
        //     fast = fast->next->next;
        // }

        // slow->val = slow->next->val;
        // slow->next = slow->next->next;

        // return head;

        // Time Complexity - O(n) Space Complexity - O(1)
        // This passes all test cases but there is a catch this may be not deleting node but editing value of middle node. To handle this precisely we can use an extra node;

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;
        if(!head || head->next == nullptr) return nullptr;
        while(fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;

        return head;
    }
};