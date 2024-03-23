
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
#define MOD 1000000007


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


ll preidx[N], sufidx[N];

void Solve(){
    ll n,npre,nsuf;

    cin>>n>>npre>>nsuf;
    rng(i,0,npre-1){
        cin>>preidx[i];
        preidx[i]--;
    }
    rng(i,0,nsuf-1){
        cin>>sufidx[i];
        sufidx[i]--;
    }
    if(preidx[npre-1]!=sufidx[0] || preidx[0]!=0 || sufidx[nsuf-1]!=n-1){
        cout<<0<<'\n';
        return;
    }
    int mxidx=preidx[npre-1];

    reverse(sufidx,sufidx+nsuf);
    rng(i,0,nsuf-1) sufidx[i]=n-1-sufidx[i];

    ll res1=fact[preidx[0]];
    rng(i,0,npre-2){
        res1=(res1*nCr(preidx[i+1]-1,preidx[i])%MOD)*fact[preidx[i+1]-preidx[i]-1]%MOD;
    }
    ll res2=fact[sufidx[0]];
    rng(i,0,nsuf-2){
        res2=(res2*nCr(sufidx[i+1]-1,sufidx[i])%MOD)*fact[sufidx[i+1]-sufidx[i]-1]%MOD;
    }
    ll res=res1*res2%MOD*nCr(n-1,mxidx)%MOD;
    cout<<(res+MOD)%MOD<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    fill_fact();
    while(t--){
        Solve();
    }
    return 0;
}

