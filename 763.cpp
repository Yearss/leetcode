#include<vector>
#include<string>

using namespace std;

class Solution {
private:
    bool checkValid(vector<int>& a, vector<int>& b){
        for(char c = 'a'; c <= 'z'; c++){
            if(a[c - 'a'] > 0 && b[c - 'a'] > 0)
                return false;
        }
        return true;
    }
public:
    vector<int> partitionLabels(string S) {

        vector<int> leftCnt(50);
        vector<int> rightCnt(50);

        //初始化
        int N = S.size();
        for(int i = 0; i < N; i++){
            rightCnt[S[i] - 'a'] ++;
        }

        vector<int> ret;
        int start = -1, i = 0;
        // 枚举每一个分割点
        for(i = 0; i < N - 1; i++){
            leftCnt[S[i] - 'a'] += 1;
            rightCnt[S[i] - 'a'] -= 1;
            if(checkValid(leftCnt, rightCnt)){
                ret.push_back(i - start);
                start = i;
            }
        }
        ret.push_back(i - start);
        return ret;
       
    }
};