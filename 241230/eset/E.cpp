
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
int tp[N];

void Solve(){
    ll n;
    cin>>n;
    rng(i,0,n-1) edges[i].clear();
    rng(i,0,n-2){
        int a,b;
        cin>>a>>b;
        a--, b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    ll leaf_cnt=0;
    rng(i,0,n-1) if(edges[i].size()==1) leaf_cnt++;
    ll res=leaf_cnt*(n-leaf_cnt);
    fill(tp,tp+n,2);
    rng(i,0,n-1){
        if(edges[i].size()==1){
            tp[i]=0;    
            continue;
        }
        bool flag=0;
        for(auto next : edges[i]){
            if(edges[next].size()==1) flag=1;
        }
        if(flag) tp[i]=1;
    }
    ll qcnt=0;
    rng(i,0,n-1) if(tp[i]==2) qcnt++;
    rng(i,0,n-1){
        if(tp[i]==1){
            ll cnt=0;
            for(auto next : edges[i]){
                if(tp[next]>=1) cnt++;
            }
            if(cnt>=2) res+=(qcnt*(cnt-1));
        }
    }
    cout<<res<<'\n';
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

