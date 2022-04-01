//  link:https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
//  Topic: Linked list

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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(!head || !head->next)
            return head;
        
        
        if(head->val!=head->next->val)
        {
            head->next=deleteDuplicates(head->next);
            return head;
        }
        
        else
            while(head->next!=NULL && head->val==head->next->val)
                head=head->next;
        
        return deleteDuplicates(head->next);
    }
};
