// 
//./E<test.txt

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
#define N 404040

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

int datas[N];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fill_fact();
    int n;
    cin>>n;
    for(int i=0; i<n+1; i++){
        cin>>datas[i];
    }
    ll res=0;
    for(int i=0; i<n+1; i++){
        if(datas[i]==0) break;
        //cout<<"nCr "<<i+datas[i]<<' '<<i+1<<' '<<nCr(i+datas[i],i+1)<<endl;
        res=(res+nCr(i+datas[i],i+1))%MOD;
    }
    cout<<res<<endl;
    return 0;
}