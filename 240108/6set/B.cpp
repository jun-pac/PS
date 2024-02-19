
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

#define N 200030
#define MOD 1000000007
#define INF 1000000007  


long long fact[N], f_inv[N];

void fill_fact(){
    fact[0]=1;
    for(int i=1; i<N; i++) fact[i]=fact[i-1]*i%MOD;
    fill(f_inv,f_inv+N,1);
    for(int k=0; k<30; k++){
        for(int i=0; i<N; i++){
            f_inv[i]=f_inv[i]*f_inv[i]%MOD;
            if((MOD-2)&(1<<(29-k))) f_inv[i]=f_inv[i]*fact[i]%MOD;
        }
    }
}

long long nCr(int n, int r){
    return ((fact[n]*f_inv[r])%MOD)*f_inv[n-r]%MOD;
}

#define MAX_DIGIT 62

// Remember (ak)*(bk)^(-1) === a*b^(-1) === (ak%P)*(bk%P)^(-1) (mod P)
long long ari_inv(long long num){
    // Calculate num^(MOD-2)
    long long res=1, mult=num;
    for(int i=0; i<MAX_DIGIT; i++){
        if((MOD-2)&(1LL<<i)){
            res=(res*mult)%MOD;
        }
        mult=(mult*mult)%MOD;
    }
    return res;
}


vc<int> edges[N];
int sz[N];

// 각 idx 이하의 sz만 알면 되네요
int DFS(int idx, int p){
    int res=1;
    for(int next : edges[idx]){
        if(next!=p) res+=DFS(next, idx);
    }
    return sz[idx]=res;
}


void Solve(){
    int n,k,a,b;
    cin>>n>>k;
    rng(i,0,n-1) edges[i].clear();
    rng(i,0,n-2){
        cin>>a>>b;
        a--, b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    if(k%2==1){
        cout<<1<<'\n';
        return;
    }
    DFS(0,-1);
    ll res=0;
    rng(i,0,n-1){
        if(sz[i]>=k/2 && n-sz[i]>=k/2){
            res=(res+nCr(sz[i],k/2)*nCr(n-sz[i],k/2))%MOD;
        }
    }
    //cout<<res<<"\n";
    cout<<(res*ari_inv(nCr(n,k))%MOD+MOD+1)%MOD<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    fill_fact();
    //cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

