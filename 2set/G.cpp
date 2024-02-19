
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

#define N 2000200
#define MOD 998244353
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


ll num[4];


void Solve(){
    rng(i,0,3) cin>>num[i];
    if(abs(num[0]-num[1])>=2){
        cout<<0<<'\n';
        return;
    }
    if(num[0]==0 && num[1]==0){
        cout<<((num[2]==0 || num[3]==0)?1:0)<<'\n';
        return;
    }
    if(num[0]!=num[1]){
        ll mx=max(num[0],num[1]);
        ll mul1=(num[2]==0?1:nCr(mx+num[2]-1,num[2]));
        ll mul2=(num[3]==0?1:nCr(mx+num[3]-1,num[3]));
        cout<<((mul1*mul2)%MOD+MOD)%MOD<<'\n';
    }
    else{
        ll mul1=(num[2]==0?1:nCr(num[0]+1+num[2]-1,num[2]));
        ll mul2=(num[3]==0?1:nCr(num[0]+num[3]-1,num[3]));
        ll mul3=(num[2]==0?1:nCr(num[0]+num[2]-1,num[2]));
        ll mul4=(num[3]==0?1:nCr(num[0]+1+num[3]-1,num[3]));
        cout<<((mul1*mul2%MOD+mul3*mul4%MOD)%MOD+MOD)%MOD<<'\n';
    }
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

