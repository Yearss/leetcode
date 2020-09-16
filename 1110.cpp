#include <vector>
#include <unordered_set>

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
    TreeNode* delNodesInner(TreeNode* root, unordered_set<int>& us, vector<TreeNode*>& ret){
        
        if(root == nullptr)
            return nullptr;

        if(us.count(root->val)){
            us.erase(us.find(root->val));
            auto node1 = delNodesInner(root->left, us, ret);
            auto node2 = delNodesInner(root->right, us, ret);
            if(node1 != nullptr) ret.push_back(node1);
            if(node2 != nullptr) ret.push_back(node2);

            return nullptr;
        }
        else{
            root->left = delNodesInner(root->left, us, ret);
            root->right = delNodesInner(root->right, us, ret);
            return root;
        }
        
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> us(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ret;
        auto node = delNodesInner(root, us, ret);
        if(node != nullptr) ret.push_back(node);
        return ret;
    }
};