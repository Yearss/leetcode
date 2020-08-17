
#include <vector>

using namespace std;

class Solution {
public:
    int numTeams(vector<int>& rating) {

        int N = rating.size();

        // f1 递减序列， f2递增序列
        vector<int> f1(N, 0), f2(N, 0);

        // 遍历以index结尾的长度为2的递增序列和递减序列
        for(int i = 0; i < N; i++){
            for(int j = 0; j < i; j++){
                if(rating[j] > rating[i])
                    f1[i] += 1;
                else if(rating[j] < rating[i])
                    f2[i] += 1;
            }
        }

        int ascRet = 0, descRet = 0;
        // DP 计算长度为3的递增序列和递减序列
        for(int i = 0; i < N; i++){
            for(int j = 0; j < i; j++){
                if(rating[i] > rating[j] && f2[j] > 0)
                    ascRet += f2[j];
                else if(rating[i] < rating[j] && f1[j] > 0)
                    descRet += f1[j];
            }
        }
        
        return ascRet + descRet;
    }
};