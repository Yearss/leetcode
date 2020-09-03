#include <vector>
#include <unordered_map>
#include <string> 

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
    int goodNodes(TreeNode* root, int curMax){

        if(root == nullptr)
            return 0;
        
        int newMax = max(curMax, root->val);
        auto retLeft = goodNodes(root->left, newMax);
        auto rightLeft = goodNodes(root->right, newMax);

        return root->val >= curMax ? retLeft + rightLeft + 1 : retLeft + rightLeft;

    }


public:
    int goodNodes(TreeNode* root) {

        return goodNodes(root, -1e9);
        
    }
};