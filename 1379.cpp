
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };


class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(cloned->val == target->val)
            return cloned;
        if(cloned->left != nullptr){
            auto ret = getTargetCopy(original, cloned->left, target);  
            if(ret != nullptr)
                return ret;     
        }
        if(cloned->right != nullptr){
            auto ret = getTargetCopy(original, cloned->right, target);
            if(ret != nullptr)
                return ret;
        }
        return nullptr;
               
    }
};