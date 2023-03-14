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
    void helper(TreeNode* root, int value,  int &ans)
    {
        if( !root ) return;
        value *= 10;
        value += root -> val;
        if( !root -> left && !root -> right )
        {
            ans += value;
            return;
        }
        helper( root -> left, value, ans);
        helper( root -> right, value, ans);
    }
    
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        helper( root, 0, ans);
        return ans;
    }
};