
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[1001][1001];
        memset(dp, 0, sizeof(dp));
        
        int M = text1.size(), N =text2.size();

        for(int i = 1; i <= M; i++){
            for(int j = 1; j <= N; j++){
                
                if(text1[i - 1] == text2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[M][N];
    }
};