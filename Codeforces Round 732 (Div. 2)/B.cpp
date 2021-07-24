#include <bits/stdc++.h>

using namespace std;

const int MX = 1e5 + 5;

int t, n, m;
string s;
char ans[MX];

int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        memset(ans, 0, sizeof(char) * (m + 1));
        for(int i = 0; i < 2 * n - 1; i++){
            cin >> s;
            for(int j = 0; j < m; j++) ans[j] ^= s[j];
        }
        cout << ans << endl;
    }
}
