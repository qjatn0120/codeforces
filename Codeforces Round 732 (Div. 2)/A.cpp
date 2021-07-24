#include <bits/stdc++.h>

using namespace std;

const int MX = 105;

int t, n, a[MX], b[MX];

int main(){
    cin.tie(nullptr), ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> n;
        int suma = 0, sumb = 0;
        for(int i = 0; i < n; i++) cin >> a[i], suma += a[i];
        for(int i = 0; i < n; i++) cin >> b[i], a[i] -= b[i], sumb += b[i];
        if(suma != sumb){
            cout << "-1\n";
            continue;
        }
        int p1 = 0, p2 = 0;
        vector <pair<int, int> > ans;
        while(1){
            while(a[p1] <= 0 && p1 < n) p1++;
            while(a[p2] >= 0 && p2 < n) p2++;
            if(p1 == n || p2 == n) break;
            ans.push_back({p1 + 1, p2 + 1});
            a[p1]--, a[p2]++;
        }
        cout << ((int)ans.size()) << "\n";
        for(auto p : ans) cout << p.first << " " << p.second << "\n";
    }
}

