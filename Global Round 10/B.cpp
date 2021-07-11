#include <bits/stdc++.h>

using namespace std;

const int MX = 2e5 + 5;

int t, n, a[MX];
long long int k;
void op(){
    int MX = a[0];
    for(int i = 1; i < n; i++) MX = max(MX, a[i]);
    for(int i = 0; i < n; i++) a[i] = MX - a[i];
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %lld", &n, &k);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        if(k) op(), k--;
        if(k) op(), k--;
        k %= 2;
        if(k) op();
        for(int i = 0; i < n; i++) printf("%d ", a[i]);
        printf("\n");
    }
}