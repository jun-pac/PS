
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

int datas[N];
array<int,3> deps[N]; // dependencies
vc<pii> cons[N]; // 0인 경우는 바로 처리하는 게 낫다.  
int fix1[30][N], fix0[30][N];
int ans[N];

void Solve(){
    int n,q;
    cin>>n>>q;
    rng(i,0,q-1){
        int a,b,c;
        cin>>a>>b>>c;
        a--, b--;
        if(a==b){
            rng(j,0,29){
                if(c&(1<<j)){
                    //cout<<"ja "<<j<<' '<<a<<'\n';
                    fix1[j][a]=1;
                }
                else fix0[j][a]=1;
            }
        }
        else{
            cons[a].pb({b,c});
            cons[b].pb({a,c});
            rng(j,0,29){
                if(!(c&(1<<j))) fix0[j][a]=fix0[j][b]=1;
            }
        }
    }
    // win0 propagation

    rng(j,0,29){
        // 0-fix propagation
        rng(i,0,n-1){
            if(fix0[j][i]){
                for(auto next : cons[i]){ // {idx, conn_val}
                    if(next.se&(1<<j)){
                        assert(fix0[j][next.fi]==0);
                        fix1[j][next.fi]=1;
                    }
                }
            }
        }
        // Greedy : 0-fix and propagation
        rng(i,0,n-1){
            if(fix0[j][i]==0 && fix1[j][i]==0){
                fix0[j][i]=1;
                for(auto next : cons[i]){    
                    if(next.se&(1<<j)){
                        assert(fix0[j][next.fi]==0);
                        fix1[j][next.fi]=1;
                    }
                }
            }
        }
    }
    rng(i,0,29){
        rng(j,0,n-1) if(fix1[i][j]) ans[j]+=(1<<i);
    }
    rng(i,0,n-1) cout<<ans[i]<<' ';
    cout<<'\n';
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

