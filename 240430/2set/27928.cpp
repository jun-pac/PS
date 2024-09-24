
#include <bits/stdc++.h>
using namespace std;
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
typedef long long ll;


#define N 1000010
#define MOD 1000000007

ll DP[10][20]; // DP[i][j] indicates sum of the numbers starts with num i and j 0s.
ll ones[20]; // [0,1,11,111,\dots]
ll powpow[20];


ll cnt_num(int mn, ll s, ll e, ll len){ // len is 1~18 
    if(len==1){
        ll res=0;
        rng(i,s,e) res+=min(9,i);
        return res;
    }
    if(s+ones[len+1]-1==e && DP[mn][len]!=-1) return DP[mn][len];
    ll res=0;
    for(ll i=mn; i<=8; i++){
        ll l=max(s,i*ones[len]);
        ll r=min((i+1)*ones[len]-1,e);
        if(l>r) continue;
        res=(res + i*powpow[len-1]%MOD*((r-l+1)%MOD))%MOD;
        res=(res + cnt_num(i,l-i*powpow[len-1],r-i*powpow[len-1],len-1))%MOD;
    }
    // For i==9
    if(9*ones[len]<=e){
        res=(res+(e-max(s,9*ones[len])+1)%MOD*((powpow[len]-1)%MOD)%MOD)%MOD;
    }
    res=((res%MOD)+MOD)%MOD;
    if(s+ones[len+1]-1==e) DP[mn][len]=res;
    return res;
}

void Solve(){
    ll s,e;
    cin>>s>>e;
    cout<<(cnt_num(0,s,e,18)%MOD+MOD)%MOD<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ones[0]=0;
    rng(i,1,19) ones[i]=ones[i-1]*10+1;
    rng(i,0,18) powpow[i]=(i==0?1:powpow[i-1]*10);
    rng(i,0,9) fill(DP[i],DP[i]+20,-1);
    int t=1;
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}