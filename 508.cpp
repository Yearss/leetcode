
#include <vector>
#include <unordered_map>

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
    pair<unordered_map<int, int>, int> findFrequentTreeSumInner(TreeNode* root) {

        if(root == nullptr){
            return {unordered_map<int,int>(), 0};
        }
        else{

            auto leftRet = findFrequentTreeSumInner(root->left);
            auto rightRet = findFrequentTreeSumInner(root->right);

            unordered_map<int, int> um;
            for(auto iter = leftRet.first.begin(); iter != leftRet.first.end(); iter++){
                um[iter->first] = um[iter->first] + iter->second;
            }
            for(auto iter = rightRet.first.begin(); iter != rightRet.first.end(); iter++){
                um[iter->first] = um[iter->first] + iter->second;
            }

            int s = leftRet.second + rightRet.second + root->val;
            um[s] = um[s] + 1;

            return  {um, s};
        
        }
        
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {

        auto res = findFrequentTreeSumInner(root);

        int mmax = -1;
        for(auto iter = res.first.begin(); iter != res.first.end(); iter++){
            mmax = max(iter->second, mmax);
        }
        vector<int> ret;
        for(auto iter = res.first.begin(); iter != res.first.end(); iter++){
            if(iter->second == mmax)
                ret.push_back(iter->first);
        }
        return ret;
    }
};

class Solution {
private:
    int findFrequentTreeSumInner(TreeNode* root, unordered_map<int,int>& um) {

        if(root == nullptr){
            return 0;
        }
        else{

            auto leftRet = findFrequentTreeSumInner(root->left);
            auto rightRet = findFrequentTreeSumInner(root->right);

            int s = leftRet + rightRet + root->val;
            um[s] = um[s] + 1;
            return s;
        }
        
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {

        unordered_map<int,int> res;
        findFrequentTreeSumInner(root, res);

        int mmax = -1;
        for(auto iter = res.begin(); iter != res.end(); iter++){
            mmax = max(iter->second, mmax);
        }
        vector<int> ret;
        for(auto iter = res.begin(); iter != res.end(); iter++){
            if(iter->second == mmax)
                ret.push_back(iter->first);
        }
        return ret;
    }
};