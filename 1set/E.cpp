
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
vc<int> groups[N];
vc<pii> ans;

int DFS(int idx, int p){
    int subsz=1;
    int num=0;
    vc<int> temp;
    for(auto next: edges[idx]){
        if(next!=p){
            int res=DFS(next,idx);
            subsz+=res;
            if(res>0) temp.pb(next);
        }
    }
    if(subsz>=4){
        // cout<<"a "<<idx<<'\n';
        groups[idx].pb(idx);
        ans.pb({2,idx+1});
        return 0;
    }

    for(auto next: temp){
        for(auto val: groups[next]) groups[idx].pb(val);
        groups[next].clear();
    }
    groups[idx].pb(idx);
    if(subsz==3 && temp.size()==2){
        swap(groups[idx][2], groups[idx][1]);
    }
    return subsz;
}

void Solve(){
    int n;
    cin>>n;
    ans.clear();
    rng(i,0,n-1) edges[i].clear();
    rng(i,0,n-2){
        int a,b;
        cin>>a>>b;
        a--, b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    rng(i,0,n) groups[i].clear();
    DFS(0, -1);
    
    rng(i,0,n-1){
        rng(j,0,(int)groups[i].size()-1) ans.pb({1,groups[i][j]+1});
    }

    cout<<ans.size()<<'\n';
    rng(i,0,(int)ans.size()-1){
        cout<<ans[i].fi<<' '<<ans[i].se<<'\n';
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

