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
   bool isPalindrome(ListNode* head) {
       vector<int> v; ListNode *temp = head;
       while(temp != nullptr ){
           v.push_back(temp->val);
           temp = temp->next;
       }
       int low = 0, high = v.size() - 1;
       while(low < high){
           if(v[low] != v[high]) return false;
           low++; high--;
       } 
       return true;
   }
};