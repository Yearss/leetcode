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
    vector<int> maxAncestorDiffInner(TreeNode* root){
        
        if(root->left == nullptr && root->right == nullptr)
            return {root->val, root->val, 0};
        else{
            
            int mmax = root->val, mmin = root->val, mabs = -1;
            if(root->left){
                auto ret = maxAncestorDiffInner(root->left);
                mmax = max(mmax, ret[1]);
                mmin = min(mmin, ret[0]);
                mabs = max(mabs, abs(root->val - mmax));
                mabs = max(mabs, abs(root->val - mmin));
                mabs = max(mabs, ret[2]);
            }

            if(root->right){
                auto ret = maxAncestorDiffInner(root->right);
                mmax = max(mmax, ret[1]);
                mmin = min(mmin, ret[0]);
                mabs = max(mabs, abs(root->val - mmax));
                mabs = max(mabs, abs(root->val - mmin));
                mabs = max(mabs, ret[2]);
            }

            return {mmin, mmax, mabs};

        }
    }
public:
    int maxAncestorDiff(TreeNode* root) {
       auto ret = maxAncestorDiffInner(root);
       return ret[2];
    }
};