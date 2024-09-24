
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

#define N 1030
#define MOD 998244353
#define INF 1000000007 
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

ll DP[501][501];
int cons[501][501]; // [l][Nmx]=min(r)
int premnr[501][501];
ll fact[N], f_inv[N];

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


ll get_DP(int l, int r){
    if(DP[l][r]!=-1) return DP[l][r];
    if(r==l) return DP[l][r]=1;

    ll res=0;
    rng(i,l,r){
        // i가 nmx이고, [l,r]안에 속한 범위가 있는지 확인?
        if(premnr[l][i]<=r) continue;
        if(l==i) res=(res+get_DP(l+1,r))%MOD;
        else if(r==i) res=(res+get_DP(l,r-1))%MOD;
        else res=(res+get_DP(l,i-1)*get_DP(i+1,r)%MOD*(nCr(r-l,i-l)))%MOD;
    }
    return DP[l][r]=res;
}

void Solve(){
    ll n,m;
    cin>>n>>m;
    fill_fact();
    bool flag=1;
    rng(i,0,n-1) fill(cons[i],cons[i]+n,INF);
    rng(i,0,n-1) fill(premnr[i],premnr[i]+n,INF);
    rng(i,0,m-1){
        int l,r,x;
        cin>>l>>r>>x;
        l--, r--, x--;
        cons[l][x]=min(cons[l][x],r);
        if(l==r) flag=0;
    }
    if(!flag){
        cout<<0<<'\n';
        return;
    }
    rng(l,0,n-1){
        rng(x,l,n-1){
            int res=INF;
            rng(k,l,x) res=min(res,cons[k][x]);
            premnr[l][x]=res;
        }
    }
    
    rng(i,0,n-1) fill(DP[i],DP[i]+n,-1);
    cout<<(get_DP(0,n-1)%MOD+MOD)%MOD<<'\n';
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

