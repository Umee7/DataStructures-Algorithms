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
    ListNode* sortList(ListNode* head) {
        // My Bruteforce TC - O(n log n) SC - O(n)
        // vector<int> nodes; ListNode *temp = head;
        // while(temp != nullptr) {
        //     nodes.push_back(temp->val);
        //     temp = temp->next;
        // }

        // sort(nodes.begin(), nodes.end());
        // temp = head;

        // for(int i = 0; i < nodes.size(); i++) {
        //     temp->val = nodes[i];
        //     temp = temp->next;
        // }

        // return head;
    }
};