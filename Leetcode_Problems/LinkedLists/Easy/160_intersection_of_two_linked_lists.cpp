#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // My bruteforce
        // ListNode *temp1 = headA;
        // unordered_set<ListNode*> set;
        // while(temp1 != nullptr) {
        //     set.insert(temp1);
        //     temp1 = temp1->next;
        // }
        // temp1 = headB;
        // while(temp1 != nullptr) {
        //     if(set.find(temp1) != set.end()) {
        //         return temp1;
        //     }
        //     temp1 = temp1->next;
        // }
        // return nullptr;
        
        // Time Complexity - O(m + n) Space Complexity - O(n) or O(m)

        // optimal 
        ListNode *temp1 = headA, *temp2 = headB;
        
        while(temp1 != temp2) {
            temp1 = temp1 ? temp1->next : headB;
            temp2 = temp2 ? temp2->next : headA;
        }
        return temp1;

        // Time Complexity - O (m + n) Space Complexity - O(1)
    }
};