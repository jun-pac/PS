// 
//./F<test

#include <bits/stdc++.h>
#define endl '\n'
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

template<typename T>
inline T umax(T &u, T v){return u = max(u, v);}
template<typename T>
inline T umin(T &u, T v){return u = min(u, v);}

#define MOD 998244353

using namespace std;

long long fact[10000010], f_inv[10000010];

ll N;

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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n,a1,x,y,m,k;
    cin>>n>>a1>>x>>y>>m>>k;
    N=n+10;
    fill_fact();
    if(k>n){
        cout<<0<<endl;
        return 0;
    }
    ll last_b=a1;
    ll res=a1*k;
    ll Tsum=1;
    for(int i=k+1; i<=n; i++){
        ll b=(last_b*x+(Tsum*y)%MOD+a1*nCr(i,k))%MOD;
        Tsum=(Tsum+nCr(i,k))%MOD;
        res=res^(b*i);
        last_b=b;
    }
    cout<<res<<endl;
    return 0;
}