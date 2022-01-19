//  link:https://leetcode.com/problems/linked-list-cycle-ii/submissions/
//  Topic: 

#include<bits/stdc++.h>
using namespace std;

 struct ListNode 
 {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution 
{
    public:
        ListNode *detectCycle(ListNode *head) 
        {
            ListNode* fast=head;
            ListNode* slow=head;
            
            while(1)
            {
                if(!fast || !fast->next)
                    return NULL;
                
                fast=fast->next->next;
                slow=slow->next;
                
                if(fast==slow)
                    break;
            }
            
            
            fast=head;
            int cnt=0;
            
            while(fast!=slow)
            {
                fast=fast->next;
                slow=slow->next;
            }
            
            return fast;
        }
};