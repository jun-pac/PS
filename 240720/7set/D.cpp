
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
// __attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

ll datas[N];
vc<int> edges[N];
ll DP[N][20];
pll mnidx[N]; //{가장 작은 값이 나오는 j, 그때의 최솟값}

void DFS(int idx, int p){
    rng(i,0,19) DP[idx][i]=(i+1)*datas[idx];
    for(auto next : edges[idx]){
        if(next==p) continue;
        DFS(next,idx);
        ll temp=-1;
        rng(k,0,19){
            if(k!=mnidx[next].fi){
                DP[idx][k]+=mnidx[next].se;
                temp=(temp==-1?DP[next][k]:min(temp,DP[next][k]));
            }
        }
        DP[idx][mnidx[next].fi]+=temp;
    }
    ll mn=-1;
    ll midx=-1;
    rng(i,0,19){
        if(mn==-1 || mn>DP[idx][i]){
            mn=DP[idx][i];
            midx=i;
        }
    }
    mnidx[idx]={midx,mn};
}

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    //rng(i,0,n-1) cout<<"hello "<<datas[i]<<endl;
    rng(i,0,n-1) edges[i].clear();
    rng(i,0,n-2){
        int a,b;
        cin>>a>>b;
        a--, b--;
        edges[a].pb(b);
        edges[b].pb(a);
        //cout<<a<<' '<<b<<endl;
    }
    if(n==1){
        cout<<datas[0]<<'\n';
        return;
    }
    DFS(0,-1);
    cout<<mnidx[0].se<<'\n';
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

