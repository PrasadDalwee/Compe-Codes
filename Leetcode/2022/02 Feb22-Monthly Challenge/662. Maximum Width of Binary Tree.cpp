// Link: https://leetcode.com/problems/maximum-width-of-binary-tree/
// Topics: BFS, Binary Tree

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

class Solution 
{
    public:
        int widthOfBinaryTree(TreeNode* root) 
        {
            long long ans=0;
            
            queue<pair<TreeNode*,long long>> q;
            q.push({root,1});
            
            while(!q.empty())
            {
                long long size=q.size(), last, first=q.front().second;
                
                for(long long i=0;i<size;i++)
                {
                    auto node=q.front().first;
                    auto x=q.front().second - first; // indexing from 0 to avoid signed integer overflow

                    if(node->left)
                        q.push({node->left,2*x});
                    if(node->right)
                        q.push({node->right,2*x+1});
                    
                    last=x;
                    q.pop();
                }
                
                ans=max(ans,last+1); //last+1 and not last-first+1 as last=x=last-first
            }
            
            return ans;
        }
};
