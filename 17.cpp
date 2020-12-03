

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>



using namespace std;


long sum(vector<long>& vec){
    long s = 0;
    for(int i = 0; i < vec.size(); i++){
        s += vec[i];
    }
    return s;
}

vector<long> solve(vector<long>& vec, int x){
    
    int n = vec.size();
    vector<long> ret(n);
    long sum1 = sum(vec);
    int minIndex = 0;
    for(int i = 0; i < n; i++){
        if(vec[i] < vec[minIndex])
            minIndex = i;
        else if(vec[i] == vec[minIndex] && i <= x)
            minIndex = i;
    }

    for(int i = 0; i < n; i++){      
        if(i == minIndex)
            ret[i] = 0;
    
        if(x < minIndex){
            if(i <= x || i > minIndex)
                ret[i] = vec[i] - vec[minIndex] - 1;
            else
                ret[i] = vec[i] - vec[minIndex];
        }
        else if(x > minIndex) {
            if(i > minIndex && i <= x)
                ret[i] = vec[i] - vec[minIndex] - 1;
            else 
                ret[i] = vec[i] - vec[minIndex];
        }
        else{
            ret[i] = vec[i] - vec[minIndex];
        }
    }

    long sum2 = sum(ret);
    ret[minIndex] = sum1 - sum2;
    return ret;
}

int main(){

    int n, x;
    cin >> n >> x;
    vector<long> vec;
    for(int i = 0; i < n; i++){
        long t;
        cin >> t;
        vec.push_back(t);
    }

    auto ret = solve(vec, x - 1);
    for(int i = 0; i < n; i++){
        cout << ret[i] << ' ';
    }

}