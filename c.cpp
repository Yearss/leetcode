

#include <vector>
#include <string>
#include <iostream>

using namespace std;


int f(string& s, int m, int n, char target){

    int ret = 0;
    //枚举起始点
    for(int i = 0, j = 0; i < n; i++){
        while(j < n && m >= 0){
            if(s[j] != target)
                m--;
            j++;
        }
        if(j == n)
            ret = max(ret, j - i);
        else
            ret = max(ret, j - i - 1);
            
        if(s[i] != target){
            m++;
        }
    }

    return ret;

}

int main(){

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    int ret = 0;
    ret = max(ret, f(s, m, n, 'a'));
    ret = max(ret, f(s, m, n, 'b'));
        
    cout << ret;

}