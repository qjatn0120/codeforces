/*
    풀이 : 먼저 현재 좌표는 0이므로, 왼쪽으로 밀고, 오른쪽으로 밀고 두 가지 행동이 가능하다.
    하지만 왼쪽으로 얼마만큼 밀던지에 상관없이 내 오른쪽에 있는 박스(a_i > 0인 박스)는 영향을 받지 않고
    마찬가지로 그 반대도 동일하다. 따라서 좌표가 양수인 박스와 좌표가 음수인 두 박스 묶음들에 대해
    special position에 놓을 수 있는 박스의 개수를 계산한 후 더하면 된다.
    편의를 위해 좌표가 음수인 박스는 좌표를 반전하여 양수로 변환한 수 계산하였다.

    만약 박스를 민다면 몇 개의 박스는 밀려서 나란히 있고, 몇 개의 박스는 너무 멀어서 밀리지 않고 제자리에 있게 된다.
    special position b_i, b_i+1에 대해 나란히 밀린 박스의 끝이 b_i또는 b_i+1에 있을 때만 고려하면 되고
    b_i, b_i+1 사이에 있는 상황은 고려하지 않아도 된다.

    따라서 각 b_i에 대해 b_i까지 박스를 밀면 총 몇 개의 박스가 밀렸는 지를 계산하고 이를 이용해
    special position에 존재하는 박스의 개수를 구하고, 최댓값을 구하면 된다.
*/

#include <bits/stdc++.h>
 
using namespace std;
 
const int MX = 2e5 + 5; // n의 max값
 
int t, n, m, a[MX], b[MX];
vector <int> v1, v2;
 
// v1에 박스의 좌표, v2에 special position의 좌표를 저장하면
// 최대 몇 개의 박스를 special position에 놓을 수 있는 지를 반환한다.
int solve(){
    vector <bool> init;
    int cnt = 0, ret = 0; // cnt = 밀리지 않고 special position에 있는 박스의 개수, ret = special position에 있는 박스의 개수의 max값
    for(int i : v2){ // 먼저 각 b_i에 대해 그 자리에 박스가 있는 지를 검사한다.
        int idx = lower_bound(v1.begin(), v1.end(), i) - v1.begin();
        if(idx < v1.size() && v1[idx] == i) init.push_back(true), cnt++;
        else init.push_back(false);
    }

    ret = cnt; // 밀지 않았을 때 special position에 있는 박스의 개수
    for(int idx = 0; idx < v2.size(); idx++){
        int i = v2[idx];
        if(init[idx]) cnt--; // 만약 밀기 전에 special position에 박스가 있었다면, 이제 밀렸으므로 개수를 1개 줄인다.
        int box_cnt = upper_bound(v1.begin(), v1.end(), i) - v1.begin(); // 밀린 박스의 개수를 계산한다
        int num = upper_bound(v2.begin(), v2.end(), i) - upper_bound(v2.begin(), v2.end(), i - box_cnt); // num = 밀린 박스 중 special position에 있는 박스의 개수
        ret = max(ret, num + cnt); // ret를 update해준다. 
    }
    return ret;
}
 
int main(){
    cin.tie(NULL), ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < m; i++) cin >> b[i];

        // 양의 좌표에 있는 박스, special position에 대해 계산한다.
        for(int i = 0; i < n; i++){
            if(a[i] > 0) v1.push_back(a[i]);
        }
        for(int i = 0; i < m; i++){
            if(b[i] > 0) v2.push_back(b[i]);
        }
        int ans = solve();

        // 음의 좌표에 있는 박스 special position에 대해 계산한다.
        v1.clear(), v2.clear();
        for(int i = 0; i < n; i++){
            if(a[i] < 0) v1.push_back(-a[i]);
        }
        for(int i = 0; i < m; i++){
            if(b[i] < 0) v2.push_back(-b[i]);
        }
        reverse(v1.begin(), v1.end());
        reverse(v2.begin(), v2.end());
        ans += solve();
        v1.clear(), v2.clear();
        cout << ans << "\n";
    }
}