
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
    unordered_set<int> us;
    void dfs(TreeNode* root, int& ret){

        if(root){

            if(us.count(root->val))
                    us.erase(us.find(root->val));
            else
                us.insert(root->val);

            if(root->left == nullptr && root->right == nullptr && us.size() < 2){
                ret++;
            }
          
            dfs(root->left, ret);
            dfs(root->right, ret);

            if(us.count(root->val))
                    us.erase(us.find(root->val));
            else
                us.insert(root->val);
             
        }
        
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {

        int ret = 0;
        dfs(root, ret);
        
        return ret;
    }   
};