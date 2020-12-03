
#include <vector>





struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == nullptr)
            return nullptr;

        if(root == p || root == q){
            return root;
        }

        auto retLeft = lowestCommonAncestor(root->left, p, q);
        auto retRight = lowestCommonAncestor(root->right, p ,q);

        if(retLeft || retRight)
            return root;
        else
            return nullptr;

    }
};