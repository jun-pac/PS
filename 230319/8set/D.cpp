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
#define MAX_DIGIT 62

ll datas[300000];
ll sum=0;
ll fact[300001];

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


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0; i<2*n; i++) cin>>datas[i];
    sort(datas,datas+2*n);
    for(int i=0; i<n; i++) sum-=datas[i];
    for(int i=n; i<2*n; i++) sum+=datas[i];
    sum=sum%MOD;
    fact[0]=1;
    for(int i=1; i<=2*n; i++) fact[i]=(fact[i-1]*i)%MOD;
    cout<<((sum*fact[2*n]%MOD)*(ari_inv(fact[n])*ari_inv(fact[n])%MOD))%MOD<<endl;
    return 0;
}