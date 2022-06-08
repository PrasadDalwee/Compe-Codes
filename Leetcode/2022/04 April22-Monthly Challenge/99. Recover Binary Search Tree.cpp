//  link: https://leetcode.com/problems/recover-binary-search-tree/
//  Topic: Inorder Traversal, BST

#include<bits/stdc++.h>
using namespace std;


// //Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//  // Definition for singly-linked list.
//  struct ListNode 
//  {
//       int val;
//       ListNode *next;
//       ListNode() : val(0), next(nullptr) {}
//       ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
//   };

class Solution {
public:
    TreeNode* big=NULL, *small=NULL, *prev =new TreeNode(INT_MIN);
    void recoverTree(TreeNode* root) 
    {
        inorder(root);
        swap(big->val,small->val);
    }
    
    void inorder(TreeNode* root)
    {
        if(root->left)
            inorder(root->left);
        
        if(big==NULL && root->val<prev->val) //first defect ->big
        {
           big=prev;
           small=root;
        }
        
        else if(root->val<prev->val)    //latest defect ->small
            small=root;
        
        prev=root;
        
        if(root->right)
            inorder(root->right);
    }
};