

#include <vector>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {

private:
    pair<TreeNode*, int> lcaDeepestLeavesInner(TreeNode* root){
        if(root == nullptr){
            return {nullptr, 0};
        }
        else{
            auto leftRet = lcaDeepestLeavesInner(root->left);
            auto rightRet = lcaDeepestLeavesInner(root->right);

            if(leftRet.second > rightRet.second){
                return {leftRet.first, leftRet.second + 1};
            }
            else if(rightRet.second > leftRet.second){
                return {rightRet.first, rightRet.second + 1};
            }
            else{
                return {root, leftRet.second + 1};
            }
        }

    }

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        
        auto ret = lcaDeepestLeavesInner(root);

        return ret.first;
    }
};