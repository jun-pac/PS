#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for(int i = 0; i < int(n); i++) 

vector<vector<int>> g;
vector<multiset<int>> len;
multiset<int> all;

int getlen(int v){
    // ���� ���� �� + 1
    return len[v].empty() ? 1 : *len[v].begin() + 1;
}

void init(int v, int p = -1){
    for (int u : g[v]) if (u != p){
        init(u, v);
        len[v].insert(getlen(u)); 
    }
    if (int(len[v].size()) > 1){
        all.insert(*(++len[v].begin())); // all�̶�� multiset���� �� ��°�� ���� �� �ֱ�
    }
}

int ans;

void dfs(int v, int p = -1){
    ans = max(ans, min(*len[v].begin() + 1, *all.begin())); 
    // ó�� �����Ҷ��� len, all�� �ǹ��ϴ� ��?
    // ���� ���� �� + 1, all���� ���� �����Ű� ans�� �ĺ���
    
    for (int u : g[v]) if (u != p){
        // len[v] 2���̻� �ִٸ� �ι�°�� �����ָ� ����� 
        // �Ʒ� (len[u])���� ���� ���� �� + 1�� �����...? (������ �� �������ٸ�..?)
        // �׸��� len[v]���� �� ��°�� ���� �ָ� all�� �ִ´�?
        // �״ϱ� ���⼭ ���� len[v]�� �ݴ��� ������ ��Ÿ���� �ǰ�?
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