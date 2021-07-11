/*
	풀이:
	단순히 모든 경우의 수를 테스트해 보면 된다.
	A, B, C 각각에 '(' 또는 ')'를 대입하므로 총 8가지의 경우의 수에 대해
	하나라도 possible string인 경우가 존재하면 yes, 아니면 no를 출력한다.
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int t;
string a;
 
// ABC로 이루어진 string tar를 받아
// a, b, c에 ( 또는 )를 대입한 string을 반환한다.
string make(string &tar, bool a, bool b, bool c){
    string ret = "";
    for(char C : tar){
        if(C == 'A') ret += (a ? "(" : ")");
        if(C == 'B') ret += (b ? "(" : ")");
        if(C == 'C') ret += (c ? "(" : ")");
    }
    return ret;
}

// ()로 이루어진 s가 possible string인지 검사한다.
bool chk(string s){
    int cnt = 0;
    for(char c : s){
        if(c == '(') cnt++;
        else cnt--;
        if(cnt < 0) return false;
    }
    return cnt == 0;
}
 
int main(){
    cin.tie(NULL), ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> a;
        bool ans = false;
        for(int i = 0; i < 8; i++){ // 모든 경우에 대해 검사한다.
            if(chk(make(a, (i & 1) == 1, (i & 2) == 2, (i & 4) == 4))) ans = true;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}