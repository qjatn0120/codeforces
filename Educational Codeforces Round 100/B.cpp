#include <bits/stdc++.h>

using namespace std;

const int MX = 55;

long long int a[MX], n, t;

int main(){
    cin.tie(nullptr),ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++){
            long long int tmp = 1;
            while(tmp <= a[i]) tmp *= 2;
            tmp /= 2;
            cout << tmp << " ";
        }
        cout << "\n";
    }
}
