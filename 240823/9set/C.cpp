
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

bool visited[N];
vc<pii> edges;

void DFS(int a, int b){
    if(a==b) return;
    assert(visited[a] && !visited[b]);
    cout<<"? "<<a+1<<' '<<b+1<<endl;
    int res;
    cin>>res;
    assert(res!=-1);
    res--;
    if(res==a){
        edges.pb({a,b});
        visited[b]=1;
    }
    else{
        if(!visited[res]) DFS(a,res);
        assert(visited[res]);
        DFS(res,b);
    }
}

void Solve(){
    int n;
    cin>>n;
    fill(visited,visited+n,0);
    visited[0]=1;
    edges.clear();
    rng(i,1,n-1){
        if(!visited[i]) DFS(0,i);
    }
    cout<<"! ";
    rng(i,0,n-2) cout<<edges[i].fi+1<<' '<<edges[i].se+1<<' ';
    cout<<endl;
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

