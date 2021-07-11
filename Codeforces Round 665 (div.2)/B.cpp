#include <bits/stdc++.h>

using namespace std;

int t, X1, Y1, Z1, X2, Y2, Z2;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d%d %d %d", &X1, &Y1, &Z1, &X2, &Y2, &Z2);
        int cnt = min(Z1, Y2);
        int ans = cnt * 2;
        Z1 -= cnt, Y2 -= cnt;
        X1 += Z1, X2 += Y2;
        if(Z2 - X1 > 0) ans -= (Z2 - X1) * 2;
        printf("%d\n", ans);
    }
}