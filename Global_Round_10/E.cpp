#include <bits/stdc++.h>

using namespace std;

int n, q;
long long int arr[30][30], k;

int main(){
    cin >> n;
    for(int j = 0; j < n; j++)
    for(int i = 0; i < n; i++){
        if(i == 0 && j == 0) continue;
        if(i == n - 1 && j == n - 1) continue;
        arr[i][j] = ((long long int)1 << (i + j - 1));
        if(j & 1) arr[i][j] = 0;
    }
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++) cout << arr[i][j] << " ";
        cout << "\n";
    }
    cout.flush();
    cin >> q;
    while(q--){
        cin >> k;
        int x = 0, y = 0;
        cout << "1 1" << "\n";
        for(int i = 0; i < n * 2 - 2; i++){
            if(x + 1 == n) y++;
            else if(y + 1 == n) x++;
            else{
                if(arr[x + 1][y] == (k & ((long long int)1 << i))) x++;
                else y++;
            }
            cout << y + 1 << " " << x + 1 << "\n";
        }
        cout.flush();
    }
}