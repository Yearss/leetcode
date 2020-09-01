#include <vector>
#include <unordered_map>
#include <string> 
#include <utility>

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
    pair<bool, TreeNode*> pruneTreeInner(TreeNode* root){
        if(root == nullptr){
            return make_pair(false, nullptr);
        }  
        else{
            auto leftRet = pruneTreeInner(root->left);                
            auto rightRet = pruneTreeInner(root->right);
            
            if(!leftRet.first && !rightRet.first && !(root->val == 1))
                return make_pair(false, nullptr);
            
            auto newRoot = new TreeNode(root->val);
            if(leftRet.first){
                newRoot->left = leftRet.second;
            }
            if(rightRet.first){
                newRoot->right = rightRet.second;
            }
            return make_pair(true, newRoot);
        }
    }   

public:
    TreeNode* pruneTree(TreeNode* root) {
        auto ret = pruneTreeInner(root);

        return ret.second;
    }
};