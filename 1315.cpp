

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
    int sumEvenGrandparentInner(TreeNode* root, TreeNode* grandparent, TreeNode* parent){
        if(root == nullptr)
            return 0;
        
        auto lTreeRet = sumEvenGrandparentInner(root->left, parent, root);
        auto rTreeRet = sumEvenGrandparentInner(root->right, parent, root);

        if(grandparent != nullptr && grandparent->val % 2 == 0)
            return lTreeRet + rTreeRet + root->val;
        else
            return lTreeRet + rTreeRet;
    }    
public:
    int sumEvenGrandparent(TreeNode* root) {
        return sumEvenGrandparentInner(root, nullptr, nullptr);
    }
};