
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
//__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

#define N 300030
#define MOD 998244353
const ll INF=1000000000000000000;

ll brands[10001];
ll visited[10001];
vc<ll> ingre[10001];
set<pll> forbid;

void Solve(){
    ll r,s,m,d,n;
    cin>>r>>s>>m>>d>>n;
    rng(i,0,r-1){
        cin>>brands[i];   
    }
    rng(i,0,s+m+d-1){
        ll k;
        cin>>k;
        rng(j,0,k-1){
            int a;
            cin>>a;
            a--;
            ingre[i].pb(a);
        }
    }
    rng(i,0,n-1){
        ll a,b,c;
        cin>>a>>b;
        a--, b--;
        forbid.insert({min(a,b), max(a,b)});
    }
    fill(visited,visited+r,-1);
    ll res=0;
    rng(i,0,s-1){
        rng(j,0,m-1){
            rng(k,0,d-1){
                array<ll,3> temp={i,j+s,k+s+m};
                if(forbid.find({i,j+s})!=forbid.end()) continue;
                if(forbid.find({j+s,k+s+m})!=forbid.end()) continue;
                if(forbid.find({i,k+s+m})!=forbid.end()) continue;
                ll cur=1;
                set<ll> ingre_set;
                for(ll u : ingre[i]){
                    if(ingre_set.find(u)==ingre_set.end()){
                        if(cediv(INF,brands[u])<cur){
                            cout<<"too many\n";
                            return;
                        }
                        ingre_set.insert(u);
                        cur=cur*brands[u];
                        if(cur>INF){
                            cout<<"too many\n";
                            return;
                        }
                    }
                }
                for(ll u : ingre[j+s]){
                    if(ingre_set.find(u)==ingre_set.end()){
                        if(cediv(INF,brands[u])<cur){
                            cout<<"too many\n";
                            return;
                        }
                        ingre_set.insert(u);
                        cur=cur*brands[u];
                        if(cur>INF){
                            cout<<"too many\n";
                            return;
                        }
                    }
                }
                for(ll u : ingre[k+s+m]){
                    if(ingre_set.find(u)==ingre_set.end()){
                        if(cediv(INF,brands[u])<cur){
                            cout<<"too many\n";
                            return;
                        }
                        ingre_set.insert(u);
                        cur=cur*brands[u];
                        if(cur>INF){
                            cout<<"too many\n";
                            return;
                        }
                    }
                }
                res=res+cur;
                if(res>INF){
                    cout<<"too many\n";
                    return;
                }
            }
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

