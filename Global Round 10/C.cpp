#include <bits/stdc++.h>

using namespace std;

const int MX = 2e5 +5;
int t, n, a[MX];
long long int ans;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        ans = 0;
        for(int i = 0; i < n - 1; i++) if(a[i] - a[i + 1] > 0) ans += a[i] - a[i + 1];
        printf("%lld\n", ans);
    }
}