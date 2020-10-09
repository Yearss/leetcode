
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
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        
        if(root == nullptr)
            return new TreeNode(val);
        else {
            
            if(root->val < val){
                auto newRoot = new TreeNode(val, root, nullptr);
                return newRoot;
            }
            else{
                root->right = insertIntoMaxTree(root->right, val);
                return root;
            }
        }
    }
};