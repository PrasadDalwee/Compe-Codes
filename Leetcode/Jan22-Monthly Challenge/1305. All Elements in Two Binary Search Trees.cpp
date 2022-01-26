//  link:https://leetcode.com/problems/all-elements-in-two-binary-search-trees/submissions/
//  Topic: BST, DFS

#include<bits/stdc++.h>
using namespace std;



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
        void fillstack(stack <TreeNode*> &s, TreeNode* root)
        {
            while(root)
            {
                s.push(root);
                root=root->left;
            }
        }
    
        void remove(stack <TreeNode*> &s)
        {
            TreeNode* top=s.top();
            s.pop();
            
            if(top->right!=NULL)
                fillstack(s,top->right);
        }
    
        vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
        {
            stack <TreeNode*> s1, s2;
            vector <int> ans;
            
            fillstack(s1,root1);
            fillstack(s2,root2);
            
            while(!(s1.empty() && s2.empty()))
            {
                      
                if(s2.empty() || ( !s1.empty() && s1.top()->val <= s2.top()->val))
                {
                    ans.push_back(s1.top()->val);
                    remove(s1);
                }
                
                else if(s1.empty() || ( !s2.empty() && s2.top()->val < s1.top()->val ))
                {
                    ans.push_back(s2.top()->val);
                    remove(s2);
                }
            }
            
            return ans;
        }
};
