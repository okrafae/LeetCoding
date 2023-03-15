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
    bool isCompleteTree(TreeNode* root) {
        
        std::queue< TreeNode* > traversalQ;
        traversalQ.push( root );
        TreeNode* prevNode = root;
        
        // Launch level-order traversal
        while( traversalQ.size() ){
            
            TreeNode* curNode = traversalQ.front();
            traversalQ.pop();
            
            if( curNode != nullptr ){
                
                if( prevNode == nullptr ){
                    // Empty in the middle means this is not a complete binary tree (not left-compact)
                    return false;
                }
                
                traversalQ.push( curNode->left );
                traversalQ.push( curNode->right );
            }
            
            // update previous node
            prevNode = curNode;
        }
        
        return true;
    }
};