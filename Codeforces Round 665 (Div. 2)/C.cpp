#include <bits/stdc++.h>

using namespace std;

const int MX = 1e5 + 5;

int t, n, a[MX];
bool able[MX];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        int Min = *min_element(a, a + n);
        vector <int> v;
        for(int i = 0; i < n; i++) if(a[i] % Min == 0) v.push_back(a[i]);
        sort(v.begin(), v.end());
        int cnt = 0;
        for(int i = 0; i < n; i++) if(a[i] % Min == 0) a[i] = v[cnt++];
        bool ans = true;
        for(int i = 1; i < n; i++) if(a[i] < a[i - 1]) ans = false;
        printf("%s\n", ans ? "YES" : "NO");
    }
}