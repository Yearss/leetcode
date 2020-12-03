

#include <vector>
#include <iostream>


using namespace std;


struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int maxPathSumInner(TreeNode* root, int& ret){

        if(root == nullptr)
            return 0;

        int leftRet = maxPathSumInner(root->left, ret);
        int rightRet = maxPathSumInner(root->right, ret);

        if(leftRet <= 0 && rightRet <= 0){
            ret = max(ret, root->val);
            return root->val;
        }
        else if(leftRet <= 0){
            ret = max(ret, root->val + rightRet);
            return root->val + rightRet;
        }
        else if(rightRet <= 0){
            ret = max(ret, root->val + leftRet);
            return root->val + leftRet;
        }
        else{
            ret = max(ret, root->val + leftRet + rightRet);
            return max(leftRet, rightRet) + root->val;
        }
        
    }
public:
    int maxPathSum(TreeNode* root) {
        int ret = -1e9;
        maxPathSumInner(root, ret);
        return ret;
    }
};