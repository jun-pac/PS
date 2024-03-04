
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
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

vc<int> edges[N];
int p[N];
int visited[N];
int depth[N];
pii pq[N]; // {depth, idx}
int n,k;

void DFS(int idx, int p, int d){
    depth[idx]=d;
    for(auto next : edges[idx]){
        if(next!=p) DFS(next, idx, d+1);
    }
}

void DFS2(int idx, int p){
    visited[idx]=1;
    for(auto next : edges[idx]){
        if(next!=p && !visited[next]) DFS2(next, idx);
    }
}

int calc(int mxh){
    // mxh>=1
    int res=0;
    fill(visited,visited+n,0);
    rng(i,0,n-1){
        if(pq[i].fi<=mxh) break;
        if(visited[pq[i].se]) continue;
        int rt=pq[i].se; // 현재 올리는 작업의 root
        //cout<<"mxh idx depth : "<<mxh<<' '<<pq[i].se<<' '<<depth[pq[i].se]<<' '<<pq[i].fi<<'\n';
        //assert(rt!=0 && p[rt]!=0);
        res++;
        for(int j=0; j<mxh-1; j++){ // mxh-1번 올리기
            if(p[rt]==0) break;
            rt=p[rt];
        }
        DFS2(rt,p[rt]);
    }
    return res;
}

void Solve(){
    cin>>n>>k;
    rng(i,0,n-1) edges[i].clear();
    p[0]=-1;
    rng(i,1,n-1){
        int x;
        cin>>x;
        x--;
        edges[x].pb(i);
        edges[i].pb(x);
        p[i]=x;
    }
    DFS(0,-1,0);
    //cout<<"depth : "; rng(i,0,n-1) cout<<depth[i]<<' '; cout<<'\n';
    rng(i,0,n-1) pq[i]={depth[i],i};
    sort(pq,pq+n);
    reverse(pq,pq+n);

    int l=1, r=n;
    while(l<r){
        int mid=(l+r)>>1;
        //cout<<"lr "<<l<<' '<<r<<' '<<calc(mid)<<'\n';
        if(calc(mid)>k) l=mid+1;
        else r=mid;
    }
    cout<<r<<'\n';
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

