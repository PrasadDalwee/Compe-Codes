//  link:https://leetcode.com/problems/add-two-numbers/
//  Topic: Linked Lists

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int sum=0, carry=0;
        auto c1=l1, c2=l2 ,p1=c1, p2=c2 ;
        
        while(c1 && c2)
        {
            sum= c1->val + c2->val + carry;
            carry=sum/10;
            sum=sum%10;
            
            p1=c1; 
            p2=c2;
            
            c1->val = c2->val = sum;
            c1=c1->next; 
            c2=c2->next;
        }
        
        if(!c1)
        {
            while(c2)
            {
                sum= c2->val + carry;
                carry=sum/10;
                sum=sum%10;
                p2=c2;
                c2->val=sum;
                c2=c2->next;
            }
            
            if(carry)
                p2->next=new ListNode(1);
            
            return l2;
        }
        
        if(!c2)
        {
            while(c1)
            {
                sum= c1->val + carry;
                carry=sum/10;
                sum=sum%10;
                p1=c1;
                c1->val=sum;
                c1=c1->next;
            }
            
            if(carry)
                p1->next=new ListNode(1);
            
            return l1;
        }
        
        
        return l1;
    }
};