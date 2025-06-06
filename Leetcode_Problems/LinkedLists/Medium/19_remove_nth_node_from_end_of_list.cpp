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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* resultHead = head;
        int sizeOfLL = 0;
        while(temp!=nullptr) {
            sizeOfLL++;
            temp = temp->next;
        }

        if(sizeOfLL == 1 && n == 1) {
            return nullptr;
        } else if((sizeOfLL - n) == 0) {
            return resultHead->next;
        }

        int count = 0;
        ListNode* temp2 = head;
        while(temp2!=nullptr){
            if(count==(sizeOfLL - n)){
                temp2->next = temp2->next->next;
                break;
            }
            count++;
            if(count==(sizeOfLL - n)){
                temp2->next = temp2->next->next;
                break;
            }
            temp2 = temp2->next;
        }
        return resultHead;
    }
};