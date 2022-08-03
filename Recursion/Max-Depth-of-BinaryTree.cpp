/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rec(TreeNode* root, int sum=0){
        
        if(root==NULL){
            return sum;
        }
        
        return  max(rec(root->left, sum+1), rec(root->right, sum+1));
    }
    int maxDepth(TreeNode* root) {
        return rec(root);
        
    }
};
