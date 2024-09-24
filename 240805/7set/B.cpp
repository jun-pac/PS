
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

#define N 400030
#define MOD 998244353
#define INF 1000000007 
//__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

vc<int> edges[N], r_edges[N];
int ts[N];
int cnt=0;
int incnt[N];


void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1){
        int a, b;
        cin>>a>>b;
        ts[i]=a;
        rng(j,0,b-1){
            int p;
            cin>>p;
            p--;
            incnt[p]++;
            edges[p].pb(i);
            r_edges[i].pb(p);
        }
    }
    //rng(i,0,n-1) if(!visited[i]) DFS(i);
    //reverse(order,order+n);
    priority_queue<pii> pq; // {-time, idx}
    rng(i,0,n-1) if(incnt[i]==0) pq.push({-ts[i],i});
    int mx=0;
    cnt=n-1;
    while(!pq.empty()){
        auto temp=pq.top();
        pq.pop();
        int idx=temp.se;
        mx=max(mx,cnt-temp.fi);
        for(auto pp:r_edges[idx]){
            incnt[pp]--;
            if(incnt[pp]==0) pq.push({-ts[pp],pp});
        }
        cnt--;
    }
    cout<<mx<<'\n';
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

