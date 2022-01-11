//  link:https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/submissions/
//  Topic: Recursion, Binary to Decimal, Depth First

#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
    public:
    int val;
    TreeNode* left=NULL;
    TreeNode* right=NULL;

    TreeNode(int x)
    {
        val=x;
    }
};

class Solution 
{
    public:
        int sum=0;
        int sumRootToLeaf(TreeNode* root) 
        {
            helper(root,0);
            return sum;
        }

        void helper(TreeNode* node, int curr)
        {
            curr=2*curr+(node->val);    //dynamic binary to decimal

            if(node->left==NULL && node->right==NULL)
            {
                sum+=curr;   
                cout<<curr<<" sum:"<<sum<<endl;
                return;
            }
                    
            if(node->left!=NULL)   helper(node->left, curr);
            if(node->right!=NULL)   helper(node->right,curr);
        }
    
};


int main()
{
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(0);
    root->right=new TreeNode(1);

    root->left->left=new TreeNode(0);
    root->left->right=new TreeNode(1);

    root->right->right=new TreeNode(1);
    root->right->right->right=new TreeNode(0);

    Solution s;
    cout<<s.sumRootToLeaf(root);
    
}
