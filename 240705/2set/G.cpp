
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define rep(i,b) rng(i,0,b-1)  
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define per(i,b) gnr(i,b-1,0)
#define pb push_back
#define eb emplace_back
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
typedef long long ll;
using pii=pair<int,int>;
using vi=vc<int>;
using uint=unsigned;
using ull=unsigned long long;
using pil=pair<int,ll>;
using pli=pair<ll,int>;
using pll=pair<ll,ll>;
using t3=tuple<int,int,int>;

#define N 300030
#define MOD 998244353
#define INF 1000000007 
#define MAX 19 // Should satisfy (1<<(MAX-1)) >= N 

int num[N];
vc<int> edges[N];
vc<int> revnum[N];
int sparse[N][MAX];
int level[N];

void DFS_init(int idx, int p){
    sparse[idx][0]=p;
    for(int i=0; i<edges[idx].size(); i++){
        int next=edges[idx][i];
        if(next!=p){
            level[next]=level[idx]+1;
            DFS_init(next,idx);
        }
    }
}

void sparse_init(int s){
    level[s]=0;
    DFS_init(s,-1);
    for(int r=1; r<MAX; r++){
        for(int i=0; i<N; i++){
            if(sparse[i][r-1]==-1) sparse[i][r]=-1;
            else sparse[i][r]=sparse[sparse[i][r-1]][r-1];
        }
    }
}

int get_LCA(int a, int b){
    if(level[a]>level[b]) swap(a,b);
    for(int r=MAX-1; r>=0; r--){
        if(sparse[b][r]!=-1 && level[a]<=level[sparse[b][r]]) b=sparse[b][r];
    }
    if(a==b) return a;
    for(int r=MAX-1; r>=0; r--){
        if(sparse[a][r]!=-1 && sparse[b][r]!=-1 && sparse[b][r]!=sparse[a][r]){
            a=sparse[a][r], b=sparse[b][r]; 
        }
    }
    return sparse[a][0];
}

ll temp;
pll DFS(int idx, int p, int col){
    pll res={0,0}; // {col의 개수, 지금까지의 길이}
    vc<pll> nress;
    for(auto next : edges[idx]){
        if(next==p) continue;
        auto nres=DFS(next,idx,col);
        nress.pb(nres);
        res.fi+=nres.fi;
        res.se+=nres.se;
    }
    rng(i,0,(int)nress.size()-1){
        temp+=(nress[i].se)*(res.fi-nress[i].fi);
    }
    if(num[idx]==col){
        temp+=res.se;
        res.fi++;
    }
    res.se+=res.fi;
    return res;
}

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-2){
        int a,b;
        cin>>a>>b;
        a--, b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    sparse_init(0);

    rng(i,0,n-1) cin>>num[i];
    rng(i,0,n-1) num[i]--;
    rng(i,0,n-1) revnum[num[i]].pb(i);
    ll res=0;
    rng(k,0,n-1){
        if(revnum[k].size()<30){
            for(auto i : revnum[k]){
                for(auto j : revnum[k]){
                    if(i>=j) continue;
                    int lca=get_LCA(i,j);
                    res+=level[i]+level[j]-2*level[lca];
                }
            }
        }
        else{
            temp=0;
            DFS(0,-1,k);
            res+=temp;
        }
    }
    cout<<res<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

