#include <bits/stdc++.h>

using namespace std;

const int MX = 1e5 + 5;

int T, n, t[MX], x[MX];

int main(){
    cin.tie(nullptr),ios::sync_with_stdio(false);
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> t[i] >> x[i];
        int pos = 0, ans = 0, tar = 0;
        for(int i = 1; i <= n; i++){
            if(tar == pos) tar = x[i];
            int dist = i == n ? INT_MAX : t[i + 1] - t[i];
            int nextpos = pos + min(max(tar - pos, -dist), dist);
            int p1 = min(pos, nextpos), p2 = max(pos, nextpos);
            if(p1 <= x[i] && x[i] <= p2) ans++;
            pos = nextpos;
        }
        cout << ans << "\n";
    }
}
