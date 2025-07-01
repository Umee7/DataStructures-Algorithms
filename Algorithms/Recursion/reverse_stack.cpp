#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      void Reverse(stack<int> &St) {
          // base case
          if(St.empty()) return;
          int ele = St.top();
          St.pop();
          Reverse(St);
          
          insertAtBottom(ele, St);
      }
      
      void insertAtBottom(int ele, stack<int> &St) {
          //base case
          if(St.empty()) {
              St.push(ele);
              return;
          } 
          
          int element = St.top();
          St.pop();
          
          insertAtBottom(ele, St);
          
          St.push(element);
      }
  };