#include <bits/stdc++.h>

using namespace std;

long long int a[3], t;

int main(){
    cin.tie(nullptr),ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        long long int shots = (a[2] - a[0]) + (a[1] - a[0]);
        if(shots % 3){
            cout << "No\n";
            continue;
        }
        if(shots % 6) a[0]--, shots += 3;
        shots /= 6;
        a[0] -= shots;
        cout << ((a[0] % 3 == 0 && a[0] >= 0) ? "Yes\n" : "No\n");
    }
}
