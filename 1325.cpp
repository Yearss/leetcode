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


public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {


        if(root == nullptr)
            return nullptr;
        
        auto leftNode = removeLeafNodes(root->left, target);
        auto rightNode = removeLeafNodes(root->right, target);

        if(leftNode == nullptr && rightNode == nullptr){
            if(root->val == target){
                return nullptr;
            }
        }

        root->left = leftNode;
        root->right = rightNode;
        return root;
       
    }
};