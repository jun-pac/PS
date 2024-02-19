// 
//./D<test

#include <bits/stdc++.h>
//#define endl '\n'
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

template<typename T>
inline T umax(T &u, T v){return u = max(u, v);}
template<typename T>
inline T umin(T &u, T v){return u = min(u, v);}


vector<int> edges[100010];
set<pair<int,int>> son_sz[100010]; // {sz, idx}
int sz[100010];
int parent[100010];
ll imp[100010];

void DFS(int idx, int p=-1){
    sz[idx]=1;
    parent[idx]=p;
    for(auto next:edges[idx]){
        if(next==p) continue;
        DFS(next,idx);
        imp[idx]+=imp[next];
        sz[idx]+=sz[next];
        son_sz[idx].insert({sz[next],-next});
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
        int n,m;
        cin>>n>>m;
        int a,b;
        for(int i=0; i<n; i++) edges[i].clear();
        for(int i=0; i<n; i++) son_sz[i].clear();
        for(int i=0; i<n; i++) cin>>imp[i];
        for(int i=0; i<n-1; i++){
            cin>>a>>b;
            a--, b--;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        DFS(0);
        for(int i=0; i<m; i++){
            cin>>a>>b;
            b--;
            if(a==1) cout<<imp[b]<<endl;
            else{
                int pp=parent[b];
                int cur=b;
                auto it=son_sz[cur].end();
                if(son_sz[cur].empty()) continue;
                //cout<<"here1"<<endl;
                int heavy=-(*(--it)).se;
                // son_sz[pp] 에서 cur을 제거
                // son_sz[pp] 에 heavy를 넣기
                //cout<<"here2"<<endl;
                son_sz[pp].erase(son_sz[pp].find({sz[cur],-cur}));
                son_sz[pp].insert({sz[cur],-heavy});

                ll c_prev=imp[cur], s_prev=imp[heavy];
                int c_prevs=sz[cur], s_prevs=sz[heavy]; 
                imp[cur]=c_prev-s_prev;
                sz[cur]=c_prevs-s_prevs;
                imp[heavy]=c_prev;
                sz[heavy]=c_prevs;

                //son_sz[cur]에서 가장 큰 놈 제거
                //cout<<"here3"<<endl;
                //cout<<(*(--son_sz[cur].end())).se<<endl;
                son_sz[cur].erase(--(son_sz[cur].end()));
                // son_sz[heavy]에 {sz[cur],cur}넣어주기
                //cout<<"here4"<<endl;
                son_sz[heavy].insert({sz[cur],-cur});
                parent[cur]=heavy;
                parent[heavy]=pp;
                
            }
        }
    return 0;
}