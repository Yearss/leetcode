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
    void inOrder(vector<int>& vec, TreeNode* root){
        if(root != nullptr){
            inOrder(vec, root->left);
            vec.push_back(root->val);
            inOrder(vec, root->right);
        }
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {

        vector<int> vec1, vec2, ret;
        inOrder(vec1, root1);
        inOrder(vec2, root2);

        int i = 0, j = 0;
        while(i < vec1.size() && j < vec2.size()){
            auto v1 = vec1[i], v2 = vec2[j];
            if(v1 < v2){
                ret.push_back(v1);
                i++;
            }
            else{
                ret.push_back(v2);
                j++;
            }
        }

        if(i == vec1.size()){
            while(j < vec2.size()){
                ret.push_back(vec2[j]);
                j++;
            }
        }
        else{
            while(i < vec1.size()){
                ret.push_back(vec1[i]);
                i++;
            }
        }
        
        return ret;
    }
};