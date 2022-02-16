//  link:https://leetcode.com/problems/swap-nodes-in-pairs/
//  Topic: Linked-Lists

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


class Solution 
{
    public:
        ListNode* swapPairs(ListNode* head) 
        {
            ListNode *node, *GP, *nextnode;
            
            node=head;
            if(node)
                nextnode=node->next;
            GP=NULL;
            
            while(node && nextnode)
            {
                if(!GP)
                    head=nextnode;
                else
                    GP->next=nextnode;
                
                GP=node;
                node->next=nextnode->next;
                nextnode->next=node;
                node=node->next;
                if(node)
                    nextnode=node->next;
            }
            
            return head;
        }
};