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
    ListNode* reverseList(ListNode* head) {
        stack<int> elements;
        ListNode *temp = head;
        while(temp != nullptr) {
            elements.push(temp->val);
            temp = temp->next;
        }
        ListNode *temp2 = head;
        while(temp2 != nullptr) {
            int element = elements.top();
            elements.pop();
            temp2->val = element;
            temp2 = temp2->next;
        }
        return head;
    }
};