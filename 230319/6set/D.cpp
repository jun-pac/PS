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

#define MOD 998244353LL

ll datas[5000];

int cnt[1000010];
ll DP[3000];
ll temp[3000];
ll fact[3000];

#define N_PRIME 1000010

bool is_prime[N_PRIME];

void build_prime(int n){
    // n<N_PRIME
    fill(is_prime+2,is_prime+n+1,true);
    for(int i=2; i<=n; i++){
        if(!is_prime[i]) continue;
        for(int j=2; i*j<=n; j++) is_prime[i*j]=false;
    }
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


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n, mx=0;
    cin>>n;
    for(int i=0; i<2*n; i++) cin>>datas[i];
    for(int i=0; i<2*n; i++) mx=max(mx,datas[i]);
    for(int i=0; i<2*n; i++) cnt[datas[i]]++;
    fact[0]=1;
    for(int i=1; i<=n; i++) fact[i]=(fact[i-1]*i)%MOD;
    build_prime(mx);

    vector<int> pp, np; // prime, not prime
    for(int i=1; i<=mx; i++){
        if(cnt[i]==0) continue;
        if(is_prime[i]) pp.push_back(cnt[i]);
        else np.push_back(cnt[i]);
    }
    //for(int i=0; i<pp.size(); i++) cout<<pp[i]<<' ';
    //cout<<endl;
    //for(int i=0; i<np.size(); i++) cout<<np[i]<<' ';
    //cout<<endl;
    
    if(pp.size()<n){
        cout<<0<<endl;
        return 0;
    }
    // for(int i=0; i<=10; i++) cout<<"ari : "<<i<<' '<<ari_inv(i)<<' '<<i*ari_inv(i)%MOD<<endl;
    DP[0]=ari_inv(fact[pp[0]]); // DP[i]는 현재까지 i+1개를 쓰는 경우를 의미한다.
    DP[1]=ari_inv(fact[pp[0]-1]);

    // cout<<"stage : "<<0<<endl;
    // for(int j=0; j<=1; j++) cout<<DP[j]<<' ';
    // cout<<endl;
    
    for(int i=1; i<pp.size(); i++){
        temp[0]= DP[0]*ari_inv(fact[pp[i]]);
        for(int j=1; j<=i; j++) temp[j]=DP[j-1]*ari_inv(fact[pp[i]-1]) + DP[j]*ari_inv(fact[pp[i]]);
        temp[i+1]=DP[i]*ari_inv(fact[pp[i]-1]);
        for(int j=0; j<=i+1; j++) DP[j]=temp[j]%MOD;

        // cout<<"stage : "<<i<<endl;
        // for(int j=0; j<=i+1; j++) cout<<DP[j]<<' ';
        // cout<<endl;
    }
    //DP[n-1];
    ll res=DP[n]*fact[n]%MOD;
    for(auto sz : np) res=res*ari_inv(fact[sz])%MOD;
    cout<<res<<endl;
    return 0;
}