//  link:https://leetcode.com/problems/insert-into-a-binary-search-tree/
//  Topic: Binary Search Tree

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if(!root)
            return new TreeNode(val);
        
        if(val>root->val)
        {
            if(!root->right)
            {
                root->right=new TreeNode(val);
                return root;
            }
            insertIntoBST(root->right,val);
        }
        
        else if(val<root->val)
        {
             if(!root->left)
            {
                root->left=new TreeNode(val);
                return root;
            }
            insertIntoBST(root->left,val);
        }
        
        return root;
    }
};

//same solution can be achieved by while