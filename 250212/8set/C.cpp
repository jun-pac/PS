
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
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

vc<int> edges[N];
pii es[N];
int undermx[N], uppermx[N];
int mx;

int DFS1(int idx, int p){    
    undermx[idx]=edges[idx].size();
    for(auto next : edges[idx]){
        if(next!=p){
            undermx[idx]=max(undermx[idx],DFS1(next,idx));
        }
    }
    return undermx[idx];
}

void DFS2(int idx, int p, int pmx){
    // mx업데이트
    // 아래로 보내기
    vc<pii> chd;
    chd.pb({pmx,p});
    for(auto next: edges[idx]){
        if(next!=p){
            chd.pb({undermx[next],next});
        }
    }
    sort(all(chd));
    reverse(all(chd));
    if(chd.size()!=1){
        mx=max(mx,chd[0].fi+chd[1].fi-1);
    }
    // 이제 문제는 자기 자신, edges[idx].size()도 고려를 해야함
    if(chd[0].se == p || edges[idx].size() >= chd[0].fi){
        for(auto next: edges[idx]){
            if(next!=p) DFS2(next,idx,edges[idx].size());
        }
    }
    else{
        chd.pb({edges[idx].size(),-1});
        sort(all(chd));
        reverse(all(chd));
        for(auto next: edges[idx]){
            if(next!=p){
                if(next==chd[0].se) DFS2(next,idx,chd[1].fi);
                else DFS2(next,idx,chd[0].fi);
            }
        }
    }
}

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) edges[i].clear();
    rng(i,0,n-2){
        int u,v;
        cin>>u>>v;
        u--, v--;
        edges[u].pb(v);
        edges[v].pb(u);
        es[i]={u,v};
    }
    mx=0;
    rng(i,0,n-2){
        mx=max(mx,(int)edges[es[i].fi].size()+(int)edges[es[i].se].size()-2);
    }
    // cout<<"near "<<mx<<'\n';
    DFS1(0,-1);
    DFS2(0,-1,-1);
    cout<<mx<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

