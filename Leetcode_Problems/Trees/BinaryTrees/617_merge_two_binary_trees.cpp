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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // Base Cases
        if(root1 == nullptr && root2 == nullptr) return nullptr;
        if(root1 != nullptr && root2 == nullptr) return root1;
        if(root1 == nullptr && root2 != nullptr) return root2;

        // Update the values 
        root1->val = root1->val + root2->val;

        // let recursion do the rest
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};