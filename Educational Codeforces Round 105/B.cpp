/*
    풀이 : 모든 경우를 테스트해 보면 된다.
    총 4개의 꼭짓점을 색칠하거나 색칠하지 않거나 각각 2가지가 가능하므로
    총 16가지의 경우 중 색칠이 가능한 경우가 하나라도 존재하면 yes 아니면 no를 출력한다.
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int t, n, U, R, D, L;
 
// 내가 칠해야 할 칸이 a라면
// 내가 칠할 수 있는 칸은 최소 0칸에서 최대 n - 2칸 이므로
// (각 꼭짓점은 이미 고려한 상태이므로 색칠할 수 없다.)
// a가 해당 범위에 있으면 true 아니면 false를 반환한다.
bool in(int a){
    return 0 <= a && a <= n - 2;
}
 
// 네 꼭짓점의 색칠 여부 a, b, c, d를 받아 현 상태에서
// 조건을 만족하도록 색칠할 수 있는 지 여부를 반환한다.
bool chk(bool a, bool b, bool c, bool d){
    int t1 = U, t2 = R, t3 = D, t4 = L;
    if(a) t1--, t4--;
    if(b) t1--, t2--;
    if(c) t3--, t2--;
    if(d) t3--, t4--;
    return in(t1) & in(t2) & in(t3) & in(t4);
}
 
int main(){
    cin.tie(NULL), ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> n >> U >> R >> D >> L;
        bool ans = false;
        for(int i = 0; i < 16; i++){ // 모든 경우의 수를 검사한다.
            if(chk(i & 1, i & 2, i & 4, i & 8)) ans = true;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}