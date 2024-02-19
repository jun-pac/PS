// 
//./D<test

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
#define NN 300030
#define N 100010

ll val[NN];
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


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n,a,b,c;
    cin>>n;
    fill_fact();
    ll res=nCr(n/3,n/6);
    for(int i=0; i<n/3; i++){
        cin>>a>>b>>c;
        if(a==b && a==c) res=(res*3)%MOD;
        else if((a==b && a<c) || (a==c && a<b) || (b==c && b<a)) res=(res*2)%MOD;
    }
    cout<<res<<endl;
    return 0;
}