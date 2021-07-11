#include <bits/stdc++.h>

using namespace std;

const int MX = (1 << 18) + 5;

int N, Q, a[MX], idx, l, r;
long long int node[MX * 3];
bool rev[MX];

void makeTree(int n, int nL, int nR){
    if(nL == nR){
        node[n] = a[nL];
        return;
    }
    int mid = nL + nR >> 1;
    makeTree(n * 2, nL, mid);
    makeTree(n * 2 + 1, mid + 1, nR);
    node[n] = node[n * 2] + node[n * 2 + 1];
}

void Update(int n, int h, int tar, int nL, int nR, int diff){
    node[n] += diff;
    if(h == 0) return;
    int mid = nL + nR >> 1;
    if(tar <= mid){
        if(rev[h]) Update(n * 2 + 1, h - 1, tar, nL, mid, diff);
        else Update(n * 2, h - 1, tar, nL, mid, diff);
    }else{
        if(rev[h]) Update(n * 2, h - 1, tar, mid + 1, nR, diff);
        else Update(n * 2 + 1, h - 1, tar, mid + 1, nR, diff);
    }
}

long long int Query(int n, int h, int L, int R, int nL, int nR){
    if(L == nL && R == nR) return node[n];
    int mid = nL + nR >> 1;
    if(R <= mid){
        if(rev[h]) return Query(n * 2 + 1, h - 1, L, R, nL, mid);
        else return Query(n * 2, h - 1, L, R, nL, mid);
    }else if(L > mid){
        if(rev[h]) return Query(n * 2, h - 1, L, R, mid + 1, nR);
        else return Query(n * 2 + 1, h - 1, L, R, mid + 1, nR);
    }else{
        if(rev[h]) return Query(n * 2 + 1, h - 1, L, mid, nL, mid) + Query(n * 2, h - 1, mid + 1, R, mid + 1, nR);
        else return Query(n * 2, h - 1, L, mid, nL, mid) + Query(n * 2 + 1, h - 1, mid + 1, R, mid + 1, nR);
    }
}

int main(){
    scanf("%d %d", &N, &Q);
    for(int i = 1; i <= (1 << N); i++) scanf("%d", &a[i]);
    makeTree(1, 1, (1 << N));
    while(Q--){
        scanf("%d", &idx);
        if(idx == 1){
            scanf("%d %d", &l, &r);
            int diff = r - Query(1, N, l, l, 1, (1 << N));
            Update(1, N, l, 1, (1 << N), diff);
        }else if(idx == 2){
            scanf("%d", &l), l++;
            while(l--) rev[l] = (!rev[l]);
        }else if(idx == 3){
            scanf("%d", &l);
            rev[l + 1] = (!rev[l + 1]);
        }else{
            scanf("%d %d", &l ,&r);
            printf("%lld\n", Query(1, N, l, r, 1, (1 << N)));
        }
    }
}