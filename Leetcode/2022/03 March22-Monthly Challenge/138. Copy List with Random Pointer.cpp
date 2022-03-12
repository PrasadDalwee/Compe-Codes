//  link:https://leetcode.com/problems/copy-list-with-random-pointer/
//  Topic: Linked List, 2 pointers

#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head1) 
    {
        if(!head1) return NULL;
        
        Node *head2= new Node(head1->val), *node1=head1->next, *node2=head2;
        unordered_map <Node*, Node*> m;
        m[head1]=head2;
        
        while(node1)
        {
            Node* next=new Node(node1->val);
            node2->next=next;
            m[node1]=next;
            
            node1=node1->next; node2=node2->next;
        }
        
        node1=head1; node2=head2;
        
        while(node1)
        {    
            node2->random = m[node1->random];
            node1=node1->next; node2=node2->next;
        }
        
        return head2;
    }
};