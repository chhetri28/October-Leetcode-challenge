/*

Recover Binary Search Tree

You are given the root of a binary search tree (BST), where exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

Follow up: A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
*/

class Solution {
public:
    TreeNode* first,*second,*prev;
    void traverse(TreeNode* root)
    {
        if(root==NULL)
            return;
        traverse(root->left);
        
        if(first==NULL&&prev->val>root->val)
            first=prev;
        if(first!=NULL&&prev->val>root->val)
            second=root;
        prev=root;
        
        traverse(root->right);
        
    }
    void recoverTree(TreeNode* root) {
        first=NULL;
        second=NULL;
        prev=new TreeNode(INT_MIN);
        traverse(root);
        swap(first->val,second->val);
    }
};