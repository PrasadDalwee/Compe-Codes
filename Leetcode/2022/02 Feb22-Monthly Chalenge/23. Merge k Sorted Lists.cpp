//  link:https://leetcode.com/problems/merge-k-sorted-lists/
//  Topic: Merge sort, Linked List

#include<bits/stdc++.h>
using namespace std;



  struct ListNode {
    int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution 
{
    public:
        
        ListNode* merge(ListNode* root1, ListNode* root2)
        {
            if(root2==NULL)
                return root1;
            
            if(root1==NULL)
                return root2;
            
            ListNode *head, *n;
            
            if(root1->val<=root2->val)
            {
                n=head=root1;
                root1=root1->next;
            }
            else
            {
                n=head=root2;
                root2=root2->next;
            }

            while(root1!=NULL && root2!=NULL)
            {
                if(root1->val<=root2->val)
                {
                    n->next=root1;
                    root1=root1->next;
                    n=n->next;
                }
                
                else
                {
                    n->next=root2;
                    root2=root2->next;
                    n=n->next;
                }
            }
            
            while(root1!=NULL)
            {
                    n->next=root1;
                    root1=root1->next;
                    n=n->next;
            }
            
            while(root2!=NULL)
            {
                    n->next=root2;
                    root2=root2->next;
                    n=n->next;
            }
            
            return head;
        }
    
        ListNode* mergeKLists(vector<ListNode*>& lists) 
        {
            if(lists.size()==0)
                return NULL;
            
            ListNode *head=lists[0];
            
            for(int i=1; i<lists.size();i++)
                head=merge(head,lists[i]);
            
            
            return head;
        }
};