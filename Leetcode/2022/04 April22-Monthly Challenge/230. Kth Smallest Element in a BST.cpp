//  link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
//  Topic: Inorder traversal, BST

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
    int ans;
    int kthSmallest(TreeNode* root, int &k) 
    {
        if(root->left && k>0)
            kthSmallest(root->left,k);
        
        k--;
        if(k==0)
        {    ans=root->val; return ans;}
        
        if(root->right && k>0)
            kthSmallest(root->right,k);
        
        return ans;
    }
};