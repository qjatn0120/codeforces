#include <bits/stdc++.h>

using namespace std;

const int MX = 3e5 + 5;

int par[MX];

int Find(int a){
    if(par[a] == a) return a;
    return par[a] = Find(par[a]);
}

void Union(int a, int b){
    a = Find(a), b = Find(b);
    if(a == b) return;
    par[b] = a;
}

int T, n, k, p[MX], x[MX], y[MX], bef[MX], to[MX], from[MX], visited[MX];
bool req[MX];

list <int> l[MX];
vector <int> adj[MX];
vector <int> ans;

int main(){
    cin >> n >> k;

    bool chk = true;

    for(int i = 1; i <= n; i++) par[i] = i;
    for(int i = 1; i <= n; i++) cin >> p[i];
    for(int i = 1; i <= k; i++){
        cin >> x[i] >> y[i];
        Union(x[i], y[i]);
        if(to[x[i]]) chk = false;
        if(from[y[i]]) chk = false;
        to[x[i]] = y[i];
        from[y[i]] = x[i];
    }

    if(!chk){
        cout << "0";
        return 0;
    }

    chk = true;
    for(int i = 1; i <= n; i++){
        if(i == par[i]){
            int pos = i;
            while(pos){
                if(visited[pos]){
                    chk = false;
                    break;
                }
                l[i].push_back(pos);
                visited[pos] = true;
                pos = to[pos];
            }
        }
    }

    if(!chk){
        cout << "0";
        return 0;
    }

    for(int i = 1; i <= n; i++){
        if(p[i] == 0) continue;
        int X = Find(p[i]), Y = Find(i);
        if(X == Y) continue;
        adj[X].push_back(Y);
        bef[Y]++;
    }

    chk = true;
    for(int i = 1; i <= n; i++){
        if(par[i] == i){
            auto it = l[i].end();
            it--;
            while(1){
                if(req[p[*it]] && (Find(p[*it]) == Find(*it))) chk = false;
                req[*it] = true;
                if(it == l[i].begin()) break;
                it--;
            }
        }
    }

    if(!chk){
        cout << "0";
        return 0;
    }

    queue <int> q;
    for(int i = 1; i <= n; i++){
        if(par[i] == i && bef[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int pos = q.front();
        q.pop();
        for(auto it = l[pos].begin(); it != l[pos].end(); it++) ans.push_back(*it);
        for(auto next : adj[pos]){
            bef[next]--;
            if(bef[next] == 0) q.push(next);
        }
    }

    if((int)ans.size() < n){
        cout << "0";
        return 0;
    }

    for(auto p : ans) cout << p << " ";
}
