/*
    풀이 : 분할 정복을 통해 풀 수 있다.
    
    만약 어떤 트리 또는 서브 트리의 leaf node 목록 v를 알고 있다면
    루트 노드의 value (value = salary of the employee)는
    부모 노드의 value는 자식 노드의 value보다 strictly하게 크다는 조건으로 인해
    max(a[v[i]][v[j]]) for i, j 로 쉽게 구할 수 있다.

    그러면 이제 각 리프 노드가 같은 서브 트리인지 아니면 다른 서브 트리에 있는 지를 계산해야 한다.
    만약 a[v[i]][v[j]]가 루트 노드의 value보다 작다면 v[i], v[j]는 같은 서브 트리
    a[v[i]][v[j]]가 루트 노드의 value와 같다면 v[i], v[j]는 다른 서브 트리에 있다는 것을 알 수 있다.
    따라서 이를 이용해 여러 묶음의 리프 노드로 분할 할 수 있다.

    여기에 분할 정복을 적용하면 풀 수 있다.
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int MX = 20005;
 
int n, a[505][505], par[MX], val[MX];
int idx; // idx에는 지금까지의 총 node의 수를 저장한다.

// 분할 정복을 수행한다.
// v : leaf node 목록
// bef : 부모 노드
void split(vector <int> v, int bef){
    if(v.size() == 1){ // leaf node가 1개인 경우(기저 상황)
        // leaf node가 곧 서브 트리 전체가 된다.
        par[v[0]] = bef;
        val[v[0]] = a[v[0]][v[0]];
        return;
    }
    idx++; // 루트 노드 1개 추가되므로 총 노드의 수가 1 증가한다.
    int max_val = 0; //루트 노드의 value
    for(int i : v) max_val = max(max_val, a[v[0]][i]);
    vector <int> tmp;
    vector <bool> check; // 이미 특정 서브 트리에 속했는 지 여부를 저장한다.
    for(int i = 0; i < v.size(); i++) check.push_back(false);
    int pos = idx;
    for(int i = 0; i < v.size(); i++){
        if(check[i]) continue;
        for(int j = i; j < v.size(); j++){
            if(a[v[i]][v[j]] < max_val){ // v[i]와 v[j]가 같은 서브 트리에 존재하면
                check[j] = true;
                tmp.push_back(v[j]); // tmp vector에 같은 서브 트리에 존재하는 리프 노드 목록을 저장한다.
            }
        }
        split(tmp, pos); // tmp vector에 있는 leaf node에 대해 계산을 한다.
        tmp.clear();
    }
    val[pos] = max_val;
    par[pos] = bef;
}
 
int main(){
    cin.tie(nullptr), ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) cin >> a[i][j];
    vector <int> v;
    for(int i = 1; i <= n; i++) v.push_back(i);
    idx = n;
    split(v, -1);
    cout << idx << "\n";
    for(int i = 1; i <= idx; i++){
        cout << val[i];
        if(i != idx) cout << " ";
    }
    cout << "\n" << n + 1 << "\n";
    for(int i = 1; i <= idx; i++){
        if(i == n + 1) continue;
        cout << i << " " << par[i] << "\n";
    }
}