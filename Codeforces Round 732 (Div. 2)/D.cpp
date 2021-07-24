#include <bits/stdc++.h>

using namespace std;

const long long int MOD = 998244353;

const int MX = 1e5 + 5;

long long int fac[MX];
int t, n, a, b;
string s;

long long int pow(long long int x, long long int y){
    if(y == 0) return 1;
    long long int tmp = pow(x, y / 2);
    tmp = (tmp * tmp) % MOD;
    if(y & 1) tmp = (tmp * x) % MOD;
    return tmp;
}

long long int C(long long int n, long long int r){
    long long int ret = fac[n];
    ret = (ret * pow(fac[r], MOD - 2)) % MOD;
    ret = (ret * pow(fac[n - r], MOD - 2)) % MOD;
    return ret;
}

int main(){
    cin.tie(nullptr), ios::sync_with_stdio(false);


    fac[0] = 1;
    for(int i = 1; i < MX; i++) fac[i] = (fac[i - 1] * i) % MOD;

    cin >> t;
    while(t--){
        cin >> n >> s;
        a = b = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0') a++;
            else if(i < n- 1 && s[i] == '1' && s[i + 1] == '1'){
                b++;
                i++;
            }
        }
        cout << C(a + b, b) << "\n";
    }
}
