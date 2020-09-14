
#include <vector>
#include <map>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {

        vector<int> vec(1);
        int N = arr.size(), v2idx[200];
        for(int i = 0; i < N; i++){
            v2idx[arr[i]] = i + 1;
            vec.push_back(arr[i]);
        }

        
        vector<int> ret;
        for(int v = N; v > 0; v--){
            int pos = v2idx[v];
            // cout << "pos: " << pos << endl;
            // 不需要翻转
            if(pos == v)
                continue;

            // 需要翻转第1次
            if(pos != 1){
                ret.push_back(pos);
                for(int i = 1; i <= pos/2; i++){
                    v2idx[vec[i]] = pos - i + 1;
                    v2idx[vec[pos-i+1]] = i;
                    swap(vec[i], vec[pos - i + 1]);
                }
            }

            // for(int i = 1; i <= N; i++)
            //     cout << vec[i] << ' ';
            // cout << endl;
            // 需要翻转第2次
            ret.push_back(v);
            for(int i = 1; i <= v / 2; i++){
                v2idx[vec[i]] = v - i + 1;
                v2idx[vec[v-i+1]] = i;
                swap(vec[i], vec[v - i + 1]);
            }

            // for(int i = 1; i <= N; i++)
            //     cout << vec[i] << ' ';
            // cout << endl;

        } 
        return ret;
    }
};

int main(){
    Solution s;
    vector<int> v = {3,2,4,1};
    s.pancakeSort(v);
}
