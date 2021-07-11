#include <bits/stdc++.h>

using namespace std;

const int MX = 2e5 + 5;

int t, n, DP[MX];
string str;

int diff(int idx, string &s1, string s2){
    int ret = 0;
    for(int i = 0; i < s2.size(); i++){
        if(s1[i + idx] != s2[i]) ret++;
    }
    return ret;
}

int cal(string s){
    s = "0" + s;
    for(int i = 1; i <= n; i++) DP[i] = MX;
    for(int i = 0; i <= n - 2; i++){
        DP[i + 2] = min(DP[i + 2], diff(i + 1, s, string("LR")) + DP[i]);//LR
        if(i <= n - 3) DP[i + 3] = min(DP[i + 3], diff(i + 1, s, string("LLR")) + DP[i]);//LLR
        if(i <= n - 3) DP[i + 3] = min(DP[i + 3], diff(i + 1, s, string("LRR")) + DP[i]);//LRR
        if(i <= n - 4) DP[i + 4] = min(DP[i + 4], diff(i + 1, s, string("LLRR")) + DP[i]);//LLRR
    }
    return DP[n];
}

int main(){
    cin >> t;
    while(t--){
        cin >> n >> str;
        int ans = cal(str);
        for(int i = 0; i < 3; i++){
            str += string(1, str[0]);
            str = str.substr(1, str.size());
            ans = min(ans, cal(str));
        }
        cout << ans << "\n";
    }
}