#include <bits/stdc++.h>
 
using namespace std;
 
const int MX = 1e5 + 5;
 
int t, n, a[MX], even[MX], odd[MX];
 
int main(){
    cin.tie(nullptr), ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        memset(even, 0, sizeof(even));
        memset(odd, 0, sizeof(odd));
        for(int i = 0; i < n; i++){
            if(i % 2) odd[a[i]]++;
            else even[a[i]]++;
        }
        bool ans = true;
        sort(a, a + n);
        for(int i = 0; i < n; i++){
            if(i % 2){
                odd[a[i]]--;
                if(odd[a[i]] < 0) ans = false;
            }else{
                even[a[i]]--;
                if(even[a[i]] < 0) ans = false;
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}