
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


#define INF 1000000007 

ll MOD;
ll fact_sum[5050];
long long fact[5050], f_inv[5050];

void fill_fact(int n){
    fact[0]=1;
    for(int i=1; i<n; i++) fact[i]=fact[i-1]*i%MOD;
    fill(f_inv,f_inv+n,1);
    for(int k=0; k<30; k++){
        for(int i=0; i<n; i++){
            f_inv[i]=f_inv[i]*f_inv[i]%MOD;
            if((MOD-2)&(1<<(29-k))) f_inv[i]=f_inv[i]*fact[i]%MOD;
        }
    }
}

long long nCr(int n, int r){
    return ((fact[n]*f_inv[r])%MOD)*f_inv[n-r]%MOD;
}


void Solve(){
    ll n;
    cin>>n>>MOD;
    fill_fact(n+1);
    rng(i,0,n) fact_sum[i]=((i==0?0:fact_sum[i-1])+fact[i])%MOD;
    ll res=0;
    ll cur=1;
    if(n%2==0){
        res=(res+fact[n-2])%MOD;
        for(ll i=1; i<=(n+1)/2-1; i++){
            cur=fact[n-3];
            rng(j,1,i-1){
                assert(n-3-j>=0);
                cur=(cur+fact[n-3-j]*(nCr(i-1,j)))%MOD;
            }
            cur=(i+1)*cur%MOD;
            res=(res+cur)%MOD;
        }
    }
    else{
        for(ll i=1; i<=(n+1)/2-1; i++){
            cur=fact[n-3];
            //cout<<"i j val "<<i<<' '<<0<<' '<<fact[n-3]<<'\n';
            rng(j,1,i-1){
                //cout<<"i j val "<<i<<' '<<j<<' '<<fact[n-3-j]*nCr(i-1,j)<<'\n';
                assert(n-3-j>=0);
                cur=(cur+fact[n-3-j]*nCr(i-1,j))%MOD;
            }
            cur=(i)*cur%MOD;
            res=(res+cur)%MOD;
        }
    }
    

    cout<<((res*n%MOD)+MOD)%MOD<<'\n';
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

