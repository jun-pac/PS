
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
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

#define N 300030
#define MOD 998244353
#define INF 1000000007 

vc<int> edges[N];
pii es[N];
bool visited[N];
int cnt;

void DFS(int idx){
    if(visited[idx]) return;
    visited[idx]=1;
    cnt++;
    for(auto next : edges[idx]){
        if(!visited[next]){
            DFS(next);
        }
    }
}

void Solve(int tt){
    int n;
    cin>>n;
    int a,b;
    rng(i,0,n-1) edges[i].clear();
    rng(i,0,n){
        cin>>a>>b;
        a--, b--;
        edges[a].pb(b);
        edges[b].pb(a);
        es[i]={a,b};
    }
    a=-1,b=-1;
    int acnt=0;
    rng(i,0,n-1){
        if(edges[i].size()==3){
            if(a==-1) a=i;
            else b=i;
            acnt++;
        }
    }
    assert(b!=-1);
    assert(acnt==2);

    rng(i,0,n-1) edges[i].clear();
    rng(i,0,n){
        int x=es[i].fi, y=es[i].se;
        if(!(x==a || y==a || x==b || y==b)){
            edges[x].pb(y);
            edges[y].pb(x);
        }
    }
    ll cnt1=-1, cnt2=-1;
    fill(visited,visited+n,0);
    rng(i,0,n-1){
        if(i!=a && i!=b && !visited[i]){
            cnt=0;
            DFS(i);
            if(cnt1==-1) cnt1=cnt;
            else cnt2=cnt;
        }
    }

    assert(cnt1!=-1);

    cnt1++;
    cnt2++;
    ll ans=((cnt1-1)*cnt1)/2+((cnt2-1)*cnt2)/2;
    cout<<"Case #"<<tt+1<<endl;
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    rng(tt,0,t-1){
        Solve(tt);
    }
    return 0;
}

