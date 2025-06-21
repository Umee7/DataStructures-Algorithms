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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // My Bruteforce 
        stack<int> s;
        ListNode *a = head, *b = head;
        while(b != nullptr) {
            s.push(b->val);
            b = b->next;
            if(s.size() == k) {
                while(!s.empty()) {
                    a->val = s.top();
                    s.pop();
                    a = a->next;
                }
            }
        }
        return head;
        // Time Complexity - O(n) Space Complexity - O(k)
    }
};