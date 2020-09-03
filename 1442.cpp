
#include <vector>
#include <unordered_map>

using namespace std;

// O(N^3)
class Solution {
public:
    int countTriplets(vector<int>& arr) {

        int N = arr.size(), ret = 0;
        for(int i = 0; i < N; i++){
            int a = 0;
            for(int j = i+1; j < N; j++){
                a = a ^ arr[j-1];
                int b = 0;
                for(int k = j; k < N; k++){
                    b = b ^ arr[k];
                    if(a == b)
                        ret ++;
                }
            }
        }
        return ret;
    }
};

// O(N^2)
class Solution {
public:
    int countTriplets(vector<int>& arr) {

        int N = arr.size();
        int ret = 0;
        for(int i = 0; i < N; i ++){
            int s = arr[i];
            for(int k = i + 1; k < N; k++){
                s = s ^ arr[k];
                if(s = 0){
                    ret += k - i;
                }
            }
        }

        return ret;
    }
};

// O(N)
class Solution {

private:
   unordered_map<int, vector<int>> um; 
public:
    int countTriplets(vector<int>& arr) {

        int N = arr.size();
        int ret = 0, s = 0;
        um[0] = vector<int>(1, -1);
        for(int i = 0; i < N; i ++){
            s = s ^ arr[i];
            if(um.count(s)){
                for(int k = 0; k < um[s].size(); k++){
                    ret += i - (um[s][k] + 1);
                }
            }
            um[s].push_back(i);
        }

        return ret;
    }
};

// O(n), O(1)
class Solution {

private:
   unordered_map<int, int> um; 
   unordered_map<int, int> cnt;
public:
    int countTriplets(vector<int>& arr) {

        int N = arr.size();
        int ret = 0, s = 0;
        um[0] = -1;
        for(int i = 0; i < N; i ++){
            s = s ^ arr[i];
            if(um.count(s)){
                cnt[s] = cnt[s] + 1;
                ret += (i - 1) * cnt[s] - um[s]; 
            }
            um[s] += i;
        }

        return ret;
    }
};
