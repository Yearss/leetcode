 
#include <vector>
#include <iostream>


using namespace std;


// 第一个小于等于target的下标
int findTarget(vector<int>& vec, int target){

    int s = 0, e = vec.size() - 1;
    while(s < e - 1){
        int m = (s + e) / 2;
        if(vec[m] > target){
            e = m - 1;
        }
        else if(vec[m] < target){
            s = m;
        }
        else{
            return m;
        }
    }
    
    if(vec[s + 1] <= target)
        return s + 1;
    else
        return s;
}


long solve(vector<int>& vec, int D){

    long ret = 0;
    int n = vec.size();
    for(int i = 0; i < n; i++){

        int target = vec[i] + D;
        int index = findTarget(vec, target);
        if(index - i > 1){
            long x = index - i - 1;
            ret = (ret + x * (x + 1) / 2) % 99997867;
        }
    }
    return ret;

}

// long solve(vector<int>& vec, int D){

//     long ret = 0, n = vec.size();
//     for(int i = 0, j = 1; i < n; i++){

//         while(j < n && vec[j] <= vec[i] + D){
//             j++;
//         }

//         if(j - i > 2){
//             long x = j - i - 2;
//             ret = (ret + x * (x + 1) / 2 ) % 99997867;
//         }
        
//     }

//     return ret;

// }

 int main(){

    int N, D;
    cin >> N >> D;
    vector<int> vec;
    for(int i = 0; i < N; i++){
        int t;
        cin >> t;
        vec.push_back(t);
    }

    cout << solve(vec, D);


 }