// 
//./E<test

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


#define MOD 1000000007
#define N 1000002

ll f[N], b[N], g[N]; // 1-based

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


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fill_fact();
    int t;
    cin>>t;
    f[1]=1, b[1]=0, g[1]=0;
    while(t--){
        ll n,m;
        cin>>n>>m;
        cout<<"n m "<<n<<' '<<m<<endl;
        ll sum=2;
        f[2]=1, b[2]=0, g[1]=0, g[2]=1;
        for(int k=3; k<=n+m+1; k++){
            b[k]=(b[k-1]+g[k-2]+(k-1)*f[k-1])%MOD;
            f[k]=(nCr(n+k-2,n)*nCr(m+k-2,m)-b[k])%MOD;
            g[k]=(g[k-1]+b[k]+f[k])%MOD;
            cout<<"k="<<k<<", b g f : "<<(b[k]>MOD/2?b[k]-MOD:b[k])<<' '<<(g[k]>MOD/2?g[k]-MOD:g[k])<<' '<<f[k]<<' '<<nCr(n+k-2,n)<<' '<<nCr(m+k-2,m)<<endl;
            sum=(sum+f[k]*k)%MOD;
        }
        cout<<sum<<endl;
    }
    return 0;
}
/*
0 0 0 2
0 0 0 2
9 - 2*1 = 7
36 - 3*7 - 3*1 = 12
100 - 4*12 - 6*7 - 4*1 = 6

b[3]=2 g[3]=2+f2=3
b[4]=24=g[3]+3*f[3]=3+21=24 g[4]=3+24+f3=34, 46
b[5]=94=g[4]+4*f[4]=34+48=82 
*/
/*
8
26
101
886336572
*/