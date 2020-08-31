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

// TLE 版本
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {

        vector<TreeNode*> ret;

        if(N == 0){
            ret.push_back(nullptr);
            return ret;
        }
        else{
            // 剩余节点数分给左右子树
            for(int i = 0; i <= N / 2; i++){
                auto left = allPossibleFBT(i);
                auto right = allPossibleFBT(N - 1 - i);
                for(int j = 0; j < left.size(); j++){
                    for(int k = 0; k < right.size(); k++){
                        if((left[j] && right[k]) || (!left[j] && !right[k])){
                            auto root = new TreeNode(0);
                            root->left = left[j];
                            root->right = right[k];
                            ret.push_back(root);
                            if(i != N - 1 - i){
                                root = new TreeNode(0);
                                root->right = left[j];
                                root->left = right[k];
                                ret.push_back(root);
                            }     
                        } 
                    }
                }
            }
            return ret;
        }
    }
};


class Solution {

private:
    unordered_map<int, vector<TreeNode*>> map;
public:
    vector<TreeNode*> allPossibleFBT(int N) {

        vector<TreeNode*> ret;

        if(map.count(N)){
            return map[N];
        }

        if(N == 0){
            ret.push_back(nullptr);
        }
        else{
            // 剩余节点数分给左右子树
            for(int i = 0; i < N; i++){
                auto left = allPossibleFBT(i);
                auto right = allPossibleFBT(N - 1 - i);
                for(int j = 0; j < left.size(); j++){
                    for(int k = 0; k < right.size(); k++){
                        if((left[j] && right[k]) || (!left[j] && !right[k])){
                            auto root = new TreeNode(0);
                            root->left = left[j];
                            root->right = right[k];
                            ret.push_back(root);
                        } 
                    }
                }
            }
        }
        map[N] = ret;
        return ret;
    }
}; 