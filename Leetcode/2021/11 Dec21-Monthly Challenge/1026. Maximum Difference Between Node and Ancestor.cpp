//  link:https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
//  Topic: recursion, Binary tree, BFS.

#include<bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    int maxdiff=0;
    
    void diff(TreeNode* root, int minn, int maxx)
    {
        if(!root)
            return;
        
        maxx=max(root->val,maxx);
        minn=min(root->val,minn);
        maxdiff=max(abs(maxx-minn),maxdiff);
        
        diff(root->left,minn,maxx);
        diff(root->right,minn,maxx);
    }

    int maxAncestorDiff(TreeNode* root) 
    {
        diff(root,root->val,root->val);
        return maxdiff;
    }
 
};