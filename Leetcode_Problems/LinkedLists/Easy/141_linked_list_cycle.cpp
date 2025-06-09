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
       unordered_map<ListNode*, int> map;
       ListNode* temp = head;
       while (temp != nullptr) {

           if (map.find(temp) != map.end()) {
               return true;
           }

           map[temp] = 1;

           temp = temp->next;
       }
       return false;
   }
};