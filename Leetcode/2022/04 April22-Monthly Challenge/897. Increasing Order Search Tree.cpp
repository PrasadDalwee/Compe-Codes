//  link:https://leetcode.com/problems/increasing-order-search-tree/
//  Topic: Recursion, Inorder-Traversal

#include<bits/stdc++.h>
using namespace std;


//Definition for a binary tree node.
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
    TreeNode* bottom=NULL; 
    TreeNode* increasingBST(TreeNode* root) 
    {   
        TreeNode* ltop=root;
        
        if(root->left)  //left subtree
        {    
            ltop=increasingBST(root->left);
            bottom->right=root;
            bottom->left=NULL;
        }
        
        bottom=root; 
        
        if(root->right)//right subtree
        {
            TreeNode* rtop=increasingBST(root->right);
            root->right=rtop;
            root->left=NULL;
            cout<<root->val<<" "<<"right \n";
        }

        root->left=NULL;
        return ltop;
    }
};