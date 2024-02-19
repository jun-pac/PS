
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
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

#define N 100030
#define MOD 998244353
#define INF 1000000007 

vc<int> edges[N];
int cnt;

void DFS(int idx, int p){
    //cout<<idx<<'\n';
    if(edges[idx].size()==1 && p!=-1) cnt++;
    for(auto next : edges[idx]){
        if(next!=p) DFS(next,idx);
    }
}

void Solve(){
    int n,a,b;
    cin>>n;
    rng(i,0,n-1) edges[i].clear();
    rng(i,0,n-2){
        cin>>a>>b;
        a--, b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    cnt=0;
    //DFS(0,-1);
    //if(edges[0].size()==1) cout<<cnt<<'\n';
    //else cout<<cnt-1<<'\n';
    if(n==1) cout<<0<<'\n';
    else{
        rng(i,0,n-1) if(edges[i].size()==1) cnt++;
        cout<<(cnt+1)/2<<'\n';
    }
    
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

