A
#include <bits/stdc++.h>

using namespace std;

int t, n, a, mem;
bool isSame;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        isSame = true;
        for(int i = 0; i < n; i++){
            scanf("%d", &a);
            if(i == 0) mem = a;
            else if(a != mem) isSame = false;
        }
        if(isSame) printf("%d\n", n);
        else  printf("1\n");
    }
}