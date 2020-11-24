
#include <vector>

using namespace std;


class CMP{
private:
    int m;
public:
    CMP(int x){
        m = x;
    }
    bool operator()(int a , int b){
        int x = abs(a - m);
        int y = abs(b - m);
        if(x > y)
            return true;
        else if(x == y)
            return a > b;
        else 
            return false;
    }
};


class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int N = arr.size();
        sort(arr.begin(), arr.end());
        int m = arr[(N - 1) / 2];
        
        sort(arr.begin(), arr.end(), CMP(m));

        return vector<int>(arr.begin(), arr.begin() + k);

    }
};