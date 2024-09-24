
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
//__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

ll datas[N];
vc<int> edges[N];

ll DFS(int idx, int p){
    ll cur=datas[idx];
    ll mn=-1;
    for(auto next : edges[idx]){
        if(p==next) continue;
        if(mn==-1) mn=DFS(next,idx);
        else mn=min(mn,DFS(next,idx));
    }
    if(idx==0){
        return cur+max(0LL,mn);
    }
    if(mn==-1) return cur;
    else if(cur>=mn) return mn;
    else return (cur+mn)/2;
}

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1){
        cin>>datas[i];
    }
    rng(i,0,n-1) edges[i].clear();

    rng(i,0,n-2){
        int a=i+1;
        int b;
        cin>>b;
        b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    cout<<DFS(0,-1)<<'\n';
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

