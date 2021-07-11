#include <bits/stdc++.h>

using namespace std;

int t, n, k;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        int ans = 0;
        if(k > n) ans = k - n;
        else if((k + n) % 2) ans = 1;
        printf("%d\n", ans);
    }
}