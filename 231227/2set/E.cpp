
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fi first
#define se second
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define rep(i,b) rng(i,0,b-1)  
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define per(i,b) gnr(i,b-1,0)
typedef long long ll;


#define MOD 998244353

ll p2(ll n){
    ll mult=2, res=1;
    for(int i=0; i<60; i++){
        if(n&(1LL<<i)){
            res=(res*mult)%MOD;
        }
        mult=(mult*mult)%MOD;
    }
    return res;
}

unordered_map<ll,ll> um1,um2;

ll res=0;
ll DFS2(ll n){
    // root가 1인 상황
    if(n==1) return 1;
    else if(um2[n]!=0) return um2[n];
    ll res=(p2((n+1)/2)-1)*(p2(n/2)-1)%MOD;
    res=(res+2*DFS2((n+1)/2)+2*DFS2(n/2))%MOD;
    um2[n]=res;
    return res;
}

ll DFS(ll n, ll k){
    //cout<<"rep "<<n<<' '<<k<<'\n';
    if(n==1){
        return k;
    }
    if(um1[n]!=0){
        return um1[n]+um2[n]*k;
    }
    
    // k*(2^(n1+n2)+(2^n1-1)*(2^n2-1));
    // 그리고 좌우에서 각각 DFS((n+1)/2,k*2), DFS((n+1)/2,k*2)
    // um1[n], um2[n]를 모두 update해야함
    // um1[n]는 k=0일 때를 기준으로 한 값임
    k=k%MOD;
    ll res=k*((p2((n+1)/2)-1)*(p2(n/2)-1)%MOD)%MOD;
    res=(res+DFS((n+1)/2,2*k)+DFS(n/2,2*k+1))%MOD;
    DFS2(n);
    um1[n]=(res-um2[n]*k)%MOD;
    //cout<<"de "<<n<<' '<<res<<' '<<um1[n]<<' '<<um2[n]<<'\n';
    return res;
}

void Solve(){
    ll n;
    cin>>n;
    //um.clear();
    //um2.clear(); // 값이 반복되더라도 계산이 가능한 값임.
    cout<<(DFS(n,1)%MOD+MOD)%MOD<<'\n';  
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

