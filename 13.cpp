
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>


using namespace std;


vector<int> solve1(vector<int>& vec){

    int n = vec.size();
    vector<int> ret(n);
    stack<pair<int, int>> st;
    st.push({-1, -1});
    for(int i = 0; i < n; i++){
        
        while(vec[i] <= st.top().second){
            st.pop();
        }
        ret[i] = st.top().first;
        st.push({i, vec[i]});
    }

    return ret;
}

vector<int> solve2(vector<int>& vec){

    int n = vec.size();
    vector<int> ret(n);
    stack<pair<int, int>> st;
    st.push({n, -1});
    for(int i = n - 1; i >= 0; i--){
        while(vec[i] <= st.top().second){
            st.pop();
        }
        ret[i] = st.top().first;
        st.push({i, vec[i]});
    }
    return ret;
}


int solve(vector<int>& vec){

    auto left = solve1(vec);
    auto right = solve2(vec);

    // for(int i = 0; i < left.size(); i++)
    //     cout << left[i] << " ";
    // cout << endl;
    // for(int i = 0; i < right.size(); i++)
    //     cout << right[i] << " ";
    // cout << endl;
    int ret = -1e9, n = vec.size();
    
    vector<int> pf(n + 1, 0);
    for(int i = 0; i < vec.size(); i++){
        pf[i + 1] = pf[i] + vec[i];
    }

    for(int i = 0; i < vec.size(); i++){
        ret = max((pf[right[i]] - pf[left[i]+1]) * vec[i], ret);
    }

    return ret;
}

int main(){

    int n, m, p;
    cin >> n;
    vector<int> vec;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        vec.push_back(t);
    }

    cout << solve(vec);
}