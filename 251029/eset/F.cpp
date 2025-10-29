#include <bits/stdc++.h>
using namespace std;
#define rng(i,a,b) for(int i=a; i<=b; i++)
#define gnr(i,a,b) for(int i=a; i>=b; i--)
#define pb push_back
#define fi first
#define se second
typedef long long ll;
template<class t> using vc=vector<t>;
#define N 200050
#define MOD 1000000007 
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
vc<int> child[N];
ll onecnt[N];
ll totcnt[N];


void DFS(int idx){
    for(auto next: child[idx]){
        DFS(next);
    }
    if(child[idx].size()==0){
        onecnt[idx]=1;
        totcnt[idx]=1;
    }
    else{
        ll oneval=0;
        ll totval=1;
        for(auto next: child[idx]){
            totval=(totval*totcnt[next])%MOD;
        }
        for(auto next: child[idx]){
            oneval+=(totval*ari_inv(totcnt[next]))%MOD*onecnt[next]%MOD;
            oneval%=MOD;
        }
        
        totval+=oneval;
        totval%=MOD;    
        // cout<<idx<<' '<<totval<<' '<<oneval<<'\n';
        onecnt[idx]=oneval;
        totcnt[idx]=totval;
    }
}

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-2){
        int x;
        cin>>x;
        x--;
        child[x].pb(i+1);
        // cout<<"s p "<<i+1<<' '<<x<<'\n';
    }
    DFS(0);
    cout<<(totcnt[0]%MOD+MOD)%MOD<<'\n';

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

