
#include <iostream>
#include <vector>


using namespace std;


int dp[1005];
int solve(string& str, int m){

   
    int n = str.size(), ret = -1e9;
    for(int i = 0; i < n; i++){
        // cout << "i: " << i << str[i]<< endl;
        for(int j = 0; j <= m; j++){

            if(i == 0){
                dp[j] = 1;
            }
            else if(j == 0){
                dp[j] = 1;
            }
            else if(str[i] == str[i - 1]){
                dp[j] = dp[j] + 1;
            }
            else{
                int r = 0;
                dp[j] = 1;
                for(int k = i - 1; k >= 0; k--){
                    if(str[k] == str[i]){
                        r += i - k - dp[j]; 
                        if(r <= m){
                            dp[j]++;
                        }
                        else{
                            break;
                        }
                    }
                }
            }      
            // cout << dp[j] << " ";   
        }
        ret = max(ret, dp[m]);
    }

    return ret;
}

int main(){


    string str;
    int m;
    cin >> str >> m;

    cout << solve(str, m);
}