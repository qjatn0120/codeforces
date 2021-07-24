#include <bits/stdc++.h>

using namespace std;

const int MX = 2e5 + 5;

int T, n, b[MX], c[MX];
bool used[MX * 2];

int main(){
    cin.tie(nullptr),ios::sync_with_stdio(false);
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1; i <= 2 * n; i++) used[i] = false;
        for(int i = 1; i <= n; i++) cin >> b[i], used[b[i]] = true;
        int tmp = 1;
        for(int i = 1; i <= 2 * n; i++){
            if(!used[i]) c[tmp++] = i;
        }

        // find x_max
        int lo = 0, hi = n;
        while(lo < hi){
            int mid = (lo + hi + 1) >> 1;
            bool chk = true;
            for(int i = 1; i <= mid; i++){
                if(b[i] > c[n - mid + i]) chk = false;
            }
            if(chk) lo = mid;
            else hi = mid - 1;
        }
        int x_max = lo;

        lo = 0, hi = n;
        while(lo < hi){
            int mid = (lo + hi) >> 1;
            bool chk = true;
            for(int i = 1; i <= n - mid; i++){
                if(b[mid + i] < c[i]) chk = false;
            }
            if(chk) hi = mid;
            else lo = mid + 1;
        }
        int x_min = lo;

        cout << (x_max - x_min + 1) << "\n";
    }
}
