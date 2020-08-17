
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
    pair<int, int> deepestLeavesSumInner(TreeNode* root){
        
        if(root == nullptr)
            return make_pair(0, 0);
        
        auto lTreeRet = deepestLeavesSumInner(root->left);
        auto rTreeRet = deepestLeavesSumInner(root->right);

        if(lTreeRet.first > rTreeRet.first)
            return make_pair(lTreeRet.first + 1, lTreeRet.second);
        else if(lTreeRet.first < rTreeRet.first)
            return make_pair(rTreeRet.first + 1, rTreeRet.second);
        else{
            if(lTreeRet.first == 0)
                return make_pair(1, root -> val);
            else
                return make_pair(rTreeRet.first + 1, lTreeRet.second + rTreeRet.second);
        }
           
            
    }

public:
    int deepestLeavesSum(TreeNode* root) {
        return deepestLeavesSumInner(root).second;
    }
};