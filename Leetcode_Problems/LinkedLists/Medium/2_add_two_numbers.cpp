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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // My Optimal solution
        ListNode *a = l1, *b = l2;
        ListNode dummy;
        ListNode *temp = &dummy;
        int carry = 0;
        while(a != nullptr && b != nullptr) {
            int number = a->val + b->val;
            number = number + carry;
            int digit = number % 10;
            carry = number / 10;
            temp->next = new ListNode(digit);
            temp = temp->next;
            a = a->next;
            b = b->next;
        }

        if(a != nullptr) {
            while(a != nullptr) {
                int number = a->val;
                number = number + carry;
                int digit = number % 10;
                carry = number / 10;
                temp->next = new ListNode(digit);
                temp = temp->next;
                a = a->next;
            }
        }

        if(b != nullptr) {
            while(b != nullptr) {
                int number = b->val;
                number = number + carry;
                int digit = number % 10;
                carry = number / 10;
                temp->next = new ListNode(digit);
                temp = temp->next;
                b = b->next;
            }
        }
        if(carry){
            int number = carry;
            int digit = number % 10;
            carry = number / 10;
            temp->next = new ListNode(digit);
            temp = temp->next;
        }

        return dummy.next;

        // Time Complexity - O(m + n) Space Complexity - O(1)

    }
};