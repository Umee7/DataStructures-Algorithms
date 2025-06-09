#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
   bool hasCycle(ListNode* head) {
    // Brute Force
    //    unordered_map<ListNode*, int> map;
    //    ListNode* temp = head;
    //    while (temp != nullptr) {
    //        if (map.find(temp) != map.end()) {
    //            return true;
    //        }
    //        map[temp] = 1;
    //        temp = temp->next;
    //    }
    //    return false;

    // My Optimal
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) {
                return true;
            }
        }
        return false;
    // Time Complexity - O(n) Space Complexity - O(1)
    // Note: compare nodes not their values
   }
};