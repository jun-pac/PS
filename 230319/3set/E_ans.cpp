#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for(int i = 0; i < int(n); i++) 

vector<vector<int>> g;
vector<multiset<int>> len;
multiset<int> all;

int getlen(int v){
    // 가장 작은 거 + 1
    return len[v].empty() ? 1 : *len[v].begin() + 1;
}

void init(int v, int p = -1){
    for (int u : g[v]) if (u != p){
        init(u, v);
        len[v].insert(getlen(u)); 
    }
    if (int(len[v].size()) > 1){
        all.insert(*(++len[v].begin())); // all이라는 multiset에다 두 번째로 작은 거 넣기
    }
}

int ans;

void dfs(int v, int p = -1){
    ans = max(ans, min(*len[v].begin() + 1, *all.begin())); 
    // 처음 시작할때의 len, all이 의미하는 바?
    // 가장 작은 거 + 1, all에서 가장 작은거가 ans의 후보군
    
    for (int u : g[v]) if (u != p){
        // len[v] 2개이상 있다면 두번째로 작은애를 지우고 
        // 아래 (len[u])에서 가장 작은 애 + 1도 지운다...? (위에서 안 지워졌다면..?)
        // 그리고 len[v]에서 두 번째로 작은 애를 all에 넣는다?
        // 그니까 여기서 부터 len[v]는 반대의 방향을 나타내는 건가?
        if (int(len[v].size()) > 1) all.erase(all.find(*(++len[v].begin())));
        len[v].erase(len[v].find(getlen(u)));
        if (int(len[v].size()) > 1) all.insert(*(++len[v].begin()));
        
        if (int(len[u].size()) > 1) all.erase(all.find(*(++len[u].begin())));
        len[u].insert(getlen(v));
        if (int(len[u].size()) > 1) all.insert(*(++len[u].begin()));
        
        dfs(u, v);
        
        if (int(len[u].size()) > 1) all.erase(all.find(*(++len[u].begin())));
        len[u].erase(len[u].find(getlen(v)));
        if (int(len[u].size()) > 1) all.insert(*(++len[u].begin()));
        
        if (int(len[v].size()) > 1) all.erase(all.find(*(++len[v].begin())));
        len[v].insert(getlen(u));
        if (int(len[v].size()) > 1) all.insert(*(++len[v].begin()));
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while (t--){
        int n;
        scanf("%d", &n);
        g.assign(n, {});
        forn(i, n - 1){
            int v, u;
            scanf("%d%d", &v, &u);
            --v, --u;
            g[v].push_back(u);
            g[u].push_back(v);
        }
        len.assign(n, {});
        all.clear();
        all.insert(n);
        init(0);
        ans = 0;
        dfs(0);
        printf("%d\n", ans);
    }
}