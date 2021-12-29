//  link:https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
//  Topic: Fast and slow pointers in linked list

#include<bits/stdc++.h>
using namespace std;

 // Definition for singly-linked list.
 struct ListNode 
 {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) 
    {
        auto fast=head;
        auto slow=head;
        auto prev=slow;
        
        if(head->next==NULL)    //edge case
            return NULL;
        
        while(fast!=NULL and fast->next!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        prev->next=prev->next->next;
        return head;
    }
};